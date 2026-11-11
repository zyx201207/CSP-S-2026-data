#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,pair<int,int>>;
const int N=1e5+5;
int c,n,m,d,p;
int w[N];
int k[505];
int a[505][N],t[505][N];
int back[N][505];
ll f[N][505];
vector<int> e[N];
void dij(int x){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	fill(f,f+505*N+1,1e9);
	for(int i=1;i<=n;i++){
		if(back[x][i])q.push({0,{x,i}});
	}
	while(q.size()){
		int h=q.top().first,a=q.top().second.first,l=q.top().second.first;
		for(int i=back[a][l]+1;i<=k[l];i++){
			q.push({h,{k[l][i],l}});
		}
		for(int i)
		q.pop();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			back[a[i][j]][i]=j
			e[i][j].push_back()
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<f[y]<<"\n";
	}
	return 0;
}

