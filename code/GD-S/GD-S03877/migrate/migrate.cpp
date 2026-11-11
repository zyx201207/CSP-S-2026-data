#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(ll i=j;i<k;i++)
#define RFOR(i,j,k) for(ll i=j;i>k;i--)
#define ll long long

int n,T,c; 
ll dp[307][307],edg[307][307],ans1,d;
void add(int u,int v,ll w,ll dps){
//	cout<<u<<' '<<v<<' '<<w<<' '<<dps<<" q??\n";
	if(edg[u][v]==-1)edg[u][v]=w,dp[u][v]=dps;
	else if(edg[u][v]>w){
		edg[u][v]=w,dp[u][v]=dps;
	}else if(edg[u][v]==w){
		dp[u][v]+=dps;
	}
	swap(u,v);
	
	if(edg[u][v]==-1)edg[u][v]=w,dp[u][v]=dps;
	else if(edg[u][v]>w){
		edg[u][v]=w,dp[u][v]=dps;
	}else if(edg[u][v]==w){
		dp[u][v]+=dps;
	}
}
ll inx[307];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		if(n>306)continue;
		ans1=0;
		FOR(i,0,n){
			cin>>inx[i];
		}
		FOR(i,0,n){
			FOR(j,0,n){
				edg[i][j]=-1;
				dp[i][j]=0;
			}
		}
		FOR(i,0,n){
			edg[i][i]=0;
		}
		sort(inx,inx+n);
		FOR(i,0,n){
			int tpos1=upper_bound(inx,inx+n,inx[i]+d)-inx;
			FOR(j,i,tpos1){
				add(i,j,1,1);
			}
		}
		FOR(k,0,n){
			FOR(i,0,n){
				if(i==k)continue;
				FOR(j,i+1,n){
					if(j==k)continue;
					if( (edg[i][k]!=-1) && (edg[j][k]!=-1) )add(i,j,edg[i][k]+edg[j][k],dp[i][k]*dp[j][k]);
				}
			}
		}
		FOR(i,0,n){
			FOR(j,0,n){
				if(i==j)continue;
//				cout<<i<<' '<<j<<' '<<edg[i][j]<<' '<<dp[i][j]<<" q2121\n";
				if(dp[i][j]==2)ans1++;
			}
		}
		cout<<ans1/2<<endl;
	}
	return 0;
} 
