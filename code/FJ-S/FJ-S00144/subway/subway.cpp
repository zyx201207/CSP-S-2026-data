#include<bits/stdc++.h>
using namespace std;
const int maxn=511,maxm=1055;
long long c,m,n,q,w[maxm],x,y,ans,d;
bool a[maxn];
struct xxx{
	long long data;
	long long time;
	long long size;
}line[maxn][maxm];
vector<int> v[maxm];
void dfs(int b,long long time){
	if(b==y){
		ans=min(time,ans);
	}
	long long e;
	for(int i=0;i<v[b].size();i++){
		for(int j=0;j<line[v[b][i]][1].size;j++){
			if(line[v[b][i]][j].data==b){
				e=b;
			}
		}
		for(int j=0;j<line[v[b][i]][1].size;j++){
			if(v[b][i]==0){
				v[b][i]=1;
				dfs(line[v[b][i]][j].data,line[v[b][i]][j].time+line[v[b][i]][e].time);
				v[b][i]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ans=0;
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans=max(ans,w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>line[i][j].data>>line[i][j].time;
			v[line[i][j].data].push_back(i);
			ans=max(ans,line[i][j].time);
			line[i][j].size=k;
		}
	}
	ans+=6;
	d=ans;
	for(int i=1;i<=q;i++){
		ans=d;
		cin>>x>>y;
		memset(a,0,sizeof(a));
		dfs(x,0);
		ans+=w[x]+w[y];
	}
	cout<<ans;
	return 0;
} 
