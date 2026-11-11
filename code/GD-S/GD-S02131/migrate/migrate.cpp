#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define int long long
const int N=310;
int c,t,n,d,dis[N][N][N],a[N],vis[N],minn[N][N],ans;
vector<int> e[N];
void dfs(int f,int now,int sum){
	dis[f][now][sum]++;
	minn[f][now]=min(minn[f][now],sum);
	for(auto u:e[now]){
		if(!vis[u]){
			vis[u]=1;
			dfs(f,u,sum+1);
			vis[u]=0;
		}
	}
}
void sol(int x){
	REP(i,1,n) vis[i]=0;
	dfs(x,x,0);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		if(d==1){
			cout<<"0\n";
			continue;
		}
		if(c<3){
			REP(i,1,n) cin>>a[i],e[i].clear();
			REP(i,1,n) REP(j,1,n){
				minn[i][j]=4e18;
				REP(k,1,n) dis[i][j][k]=0;
			}
			REP(i,1,n-1) REP(j,i+1,n) if(a[j]-a[i]<=d) e[i].push_back(j),e[j].push_back(i);
			REP(i,1,n) sol(i);
			REP(i,1,n-1) REP(j,i+1,n) if(minn[i][j]!=4e18&&dis[i][j][minn[i][j]]==2) ans++;
			cout<<ans<<"\n";	
		}
		else{
			REP(i,1,n) cin>>a[i];
			REP(i,1,n-1) REP(j,i+1,n){
				int now=i;
				vector<int> res;res.clear();
				REP(k,i+1,j){
					if(a[k]-a[now]>d&&a[k-1]-a[now]<=d) now=k-1,res.push_back(k-1);
					else if(a[k-1]-a[now]>d) break;
				}
				if(a[j]-a[now]>d) continue;
				else res.push_back(j);
				int flag=0;
				REP(k,0,res.size()-2){
					if(a[res[k]-1]+d>=a[res[k+1]]&&a[res[k]-2]+d<a[res[k+1]]){
						flag++;
						if(flag==1) ans++;
					}
					else{
						if(flag==1) ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//Oct31==Dec25?
