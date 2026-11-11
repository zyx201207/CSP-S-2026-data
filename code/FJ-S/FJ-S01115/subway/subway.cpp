#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e[100005],f[505][100005],g[505][100005],h[100005],q[100005][5],dis[10005][10005];
bool v[500005];
vector<long long>u[10005];
long long dfs(long long x,long long y,long long cnt){
	if(v[x])return 0;
	if(x==y)return cnt;
	v[x]=1;
	long long an=99999999999;
	for(auto v1:u[x])
		an=min(an,dfs(v1,y,cnt+dis[x][v1]));
	return an;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>a>>a>>b>>c>>d;
	for(int i=1;i<=b;i++){
		cin>>e[i];
		for(int j=1;j<=b;j++){
			dis[i][j]=9999999999;
		}
	}for(int i=1;i<=a;i++){
		cin>>h[i];
		for(int j=1;j<=h[i];j++){
			cin>>f[i][j]>>g[i][j];
		}for(int j=1;j<=h[i];j++){
			for(int k=1;k<=h[i];k++){
				if(j!=k){
					u[f[i][j]].push_back(f[i][k]);
					dis[f[i][j]][f[i][k]]=min(g[i][j]+g[i][k],dis[f[i][j]][f[i][k]]);
				}
			}
		}
	}for(int i=1;i<=d;i++){
		cin>>q[i][1]>>q[i][2];
	}for(int i=1;i<=d;i++){
		cout<<dfs(q[i][1],q[i][2],0)<<endl;
	}
}
