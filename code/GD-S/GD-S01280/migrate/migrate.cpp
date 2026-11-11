#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
struct owo{
	int v,k;
};
int che,T;
int n,d;
ll a[N];
int lu[N];
vector<int> e[N];
void add(int u,int v){
	e[u].push_back(v);
}
bool vis[N];
bool bfs(int st,int en){
	bool flag=0;
	int kk=-1;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	queue<owo> q;
	q.push({st,0});
	vis[st]=1;
	while(!q.empty()){
		owo fa=q.front();
		q.pop();
		if(fa.v==en){
			if(fa.k!=kk&&flag) return 0;
			if(flag==0) kk=fa.k,flag=1;
			  else return 1;
		}
		for(int i=0;i<e[fa.v].size();i++){
			int v=e[fa.v][i];
			if(vis[v]||v<=fa.v||v>en||(fa.k+1>kk&&flag)) continue;
			vis[v]=1;
			q.push({v,fa.k+1});
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>che>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d) add(i,j);
				 else break;
		for(int i=1;i<n;i++)
			for(int j=i+2;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				if(bfs(i,j)) ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
