#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int id,n,m,d,q,w[600001],k,s,t;
ll ans=9223372036854775807;
vector< vector<int> > a(600001),b(600001),c(601);
int f[50001][501];
void dfs(int x,int y,ll cnt){
	int xian,zhan;
	if(x==y){
		ans=min(ans,cnt);
		return;
	}
	for(int i=0;i<b[x].size();i++){
		xian=b[x][i];
		for(int j=0;j<c[xian].size();j++){
			zhan=c[xian][j];
			if(f[zhan][xian]==0&&zhan!=x){
				f[zhan][xian]=1;
				for(int l=0;l<b[zhan].size();l++){
					if(b[zhan][l]==xian){
						dfs(zhan,y,cnt+a[x][i]+a[zhan][l]);
						break;
					}
				}
				
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>s>>t;
			a[s].push_back(t);
			b[s].push_back(i);
			c[i].push_back(s);
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		ans=9223372036854775807;
		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				f[i][j]=0;
			}
		}
		for(int i=0;i<b[x].size();i++){
			f[x][b[x][i]]=1;
		}
		dfs(x,y,w[x]);
		cout<<ans+w[y]<<endl;
	}
	return 0;
}
