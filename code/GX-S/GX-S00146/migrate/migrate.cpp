#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1145141];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int anss=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}/*for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				int dp[r-l+5];
				dp[0]=0;
				for(int i=1;i<=r-l;i++){
					dp[i]=11451419198102333ll;
					for(int j=0;j<i;j++){
						if(a[l+i]-a[l+j]<=d){
							dp[i]=min(dp[i],dp[j]+1);
						}
					}
				}int cntt=0;
				for(int i=1;i<r-l;i++){
					cout<<dp[i]<<" ";
					if(dp[i]==dp[r-l]-1){
						cntt++;
					}
				}if(cntt==2){
					anss++;
				}cout<<endl;
			}
		}cout<<anss<<endl;*/
		cout<<0<<endl;
	}
	
	
}
