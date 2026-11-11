#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int c,t,n,d,x[5005],dp[5005],step[5005],lt[5005],rt[5005],be[5005],sum[5005],mi[11],tans[11];
void dfs(int u,int tot){
//	cout<<u<<" "<<tot<<endl;
	mi[u]=min(mi[u],tot);
	for(int j=u+1;j<=n;j++){
		if(x[j]-x[u]<=d){
			dfs(j,tot+1);
		}
	}
}
void dfs2(int u,int tot){
	if(tot==mi[u]){
		tans[u]++;
	}
	for(int j=u+1;j<=n;j++){
		if(x[j]-x[u]<=d){
			dfs2(j,tot+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c<=2){
		while(t--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int i=1;i<=n;i++){
				memset(mi,0x3f3f3f3f,sizeof(mi));
				memset(tans,0,sizeof(tans));
				dfs(i,0);
				dfs2(i,0);
				for(int j=i+1;j<=n;j++){
			//		cout<<mi[j]<<" ";
					ans+=(tans[j]==2);
				}
			//	cout<<endl;
			}
			cout<<ans<<endl;
		}
	}
	if(c<=10&&c>2){
		while(t--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int i=1;i<=n;i++){
//				cout<<i<<"-------------------"<<endl;
				step[i]=0,lt[0]=i,rt[0]=i;
				step[i+1]=1,lt[1]=i+1,be[i+1]=1;
				for(int j=i+2;j<=n;j++){
					if(x[j]-x[lt[step[j-1]]-1]<=d){
						step[j]=step[j-1];
					}
					else{
						step[j]=step[j-1]+1;
						rt[step[j-1]]=j-1;
						lt[step[j]]=j;
					}
					be[j]=step[j];
				}
//				for(int j=i;j<=n;j++){
//					cout<<step[j]<<" ";
//				}
//				cout<<endl;
				rt[step[n]]=n;
				for(int i=0;i<=n;i++){
					dp[i]=0;
				} 
				dp[i]=1,sum[i]=1,sum[i-1]=0;
				for(int j=i+1;j<=n;j++){
					int l=i,r=j-1,id=0;
					while(l<=r){
						int mid=(l+r)/2;
						if(x[j]-x[mid]<=d){
							r=mid-1,id=mid;
						}
						else{
							l=mid+1;
						}
					}
					if(id==j||!id){
						 break;
					}
					int ls=max(id,lt[step[j]-1]),rs=min(j-1,rt[step[j]-1]);
					dp[j]=min(3ll,sum[rs]-sum[ls-1]);
					sum[j]=sum[j-1]+dp[j];
					ans+=(dp[j]==2);
				//	cout<<id<<" "<<j-1<<" "<<ls<<" "<<rs<<" "<<sum[rs]<<" "<<sum[ls-1]<<" "<<dp[j]<<endl; 
				}
			}
			cout<<ans<<endl;
		}
	}  
	return 0;
}

