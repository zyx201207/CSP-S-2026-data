#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
struct owo{
	int v,k;
};
int che;
int n,m,d,Q;
ll w[N],T;
vector<int> e[N];
bool vis[N];
ll bfs(int st,int en){
	for(int i=1;i<=n;i++)
		vis[i]=0;
	queue<owo> q;
	q.push({st,0});
	vis[st]=1;
	while(!q.empty()){
		owo fa=q.front();
		q.pop();
		if(fa.v==en) return w[st]+w[en]+fa.k*T;
		for(int i=0;i<e[fa.v].size();i++){
			int v=e[fa.v][i];
			if(vis[v]) continue;
			vis[v]=1;
			q.push({v,fa.k+1});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>che>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		int a[k+5];
		ll t[k+5];
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[j];
		T=2*t[1];
		for(int j=1;j<k;j++)
			for(int f=j+1;f<=k;f++){
				e[a[j]].push_back(a[f]);
				e[a[f]].push_back(a[j]);
			}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<endl;
	}
	return 0;
}

