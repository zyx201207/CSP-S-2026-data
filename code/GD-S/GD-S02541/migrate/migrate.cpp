#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mMAXN=5009;
ll dp[mMAXN][mMAXN];
ll xi[mMAXN],minl[mMAXN][mMAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,T,n,d;
	cin>>c>>T;
	if(c<=10){
		while(T--){
			memset(dp,0,sizeof(dp));		
			cin>>n>>d;
			ll lst,len,ans=0,over=0,less=0;
			for(int i=1;i<=n;i++)cin>>xi[i];
			for(int i=1;i<=n;i++){
				//cout<<i<<" --> ";
				lst=i;
				len=0;
				for(int j=i+1;j<=n;j++){
					if(xi[j]-xi[j-1]>d){
						lst=-1;
					}
					if(lst==-1){
					//	cout<<"shit ";
						minl[i][j]=LONG_LONG_MAX;
						//cout<<j<<"INF ";
						continue;
					}
					if(xi[j]-xi[lst]>d){
						len++;
						lst=j-1;
					}
					minl[i][j]=len+1;
					//cout<<j<<":"<<len+1<<" ";
				}			
				//cout<<'\n';
			}
			for(int i=1;i<=n;i++)if(minl[i][i+1]!=LONG_LONG_MAX)dp[i][i+1]=1;
			ll sum=0;
			for(int lx=3;lx<=n;lx++){
				for(int x=1;x+lx-1<=n;x++){
					sum=0;
					ll y=x+lx-1;
					if(minl[x][y]==LONG_LONG_MAX)break;
					if(xi[y]-xi[x]<=d)dp[x][y]=1;
					for(int k=x+1;k<y;k++){
						if(minl[x][k]+minl[k][y]==minl[x][y]){
							sum+=(dp[x][k]*dp[k][y]);
							if(sum>3)break;
						}
					}
					dp[x][y]+=sum;
					if(dp[x][y]<=1){
						less++;
					}
					if(dp[x][y]==2)ans++;
					if(dp[x][y]>=3){
						dp[x][y]=3;
						over++;
					}
				}
				
			}
			cout<<ans<<'\n';
		}
	}
	else if(c==11||c==12){
		/*while(T--){
			cin>>n>>d;
			ll step,ans=0;
			for(int i=1;i<=n;i++)cin>>xi[i];
			step=d/(xi[2]-xi[1]);
			for(int i=1;i<=n;i++){
				ans+=(n)
			}
		}*/
		
	}
}
