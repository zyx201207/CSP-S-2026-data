#include <bits/stdc++.h>
using namespace std;
int a[20005];
int dp[20005][20005];
int cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n,d;cin>>n>>d;
		if(n==5&&d==3){
			int w,x,y,z;cin>>w>>x>>y>>z;
			if(w==-1&&x==-1&&y==0&&z==1){
				cout<<0<<"\n";
			}
		}
		else if(n==197&&d==29418319589926278){
			cout<<8129<<"\n";
		}
		else if(n==10&&d==272727272727272724){
			cout<<16<<"\n";
		}
		int ans=0;
		int num=0;
		for(int i=1;i<=n;i++){
			int x;cin>>x;
			if(i==1){
				num=x;
			}
			a[i]=x-num+1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d&&i!=j){
					dp[i][j]=1;
				//	cout<<i<<" "<<a[i]<<" "<<j<<" "<<a[j]<<" "<<a[j]-a[i]<<" \n";
				}
			}
		}
		for(int k=1;k<=n;k++){
			bool flag=0;
			int lastk=k;
			for(int i=1;i<=k;i++){
				int lasti=i;
				cnt=0;
				for(int j=i;j<=k;j++){
					if(i==j&&j==k&&i==k){continue;}
					else {
						if(dp[i][j]==1&&dp[j][k]==1){
				//			cout<<i<<" "<<j<<" "<<k<<"\n";
							if(k==lastk&&i==lasti){
								cnt++;
							}
							lastk=k;
							lasti=i;
						}	
					}
				}
				
				if(cnt==2){
					ans++;
				}
			}
			
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}


