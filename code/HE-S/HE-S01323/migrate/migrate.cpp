#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int M=1e4+10;
int c,t;
int n,d;
int a[N],s[N],sum[M][M],dp[M][M],ans;
void su(int a1,int b){
	memset(s,0,sizeof(s));
	for(int i=a1;i<=b;i++){
		s[i]=s[i-1]+a[i];
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			a[i]=a[i+1]-a[i];
		}
		for(int i=1;i<n;i++){
			int cnt2=i;
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				su(cnt2,j);
				bool boo=true;
				for(int k=cnt2;k<=j&&boo;k++){
					if(s[k]>d&&k!=cnt2){
						cnt++;
						cnt2=k-1;
						boo=false;
//						cout<<"k="<<k<<" s[k]="<<s[k]<<" d="<<d<<" cnt2="<<cnt2<<' '; 
					}
					if(s[k]>d&&k==cnt2){
						cnt=0;
					}
				}
//				cout<<i<<' '<<j<<' '<<cnt<<'\n';
				dp[i][j]=cnt;
			}
		}
		for(int a=1;a<=n;a++){
			for(int b=a+1;b<=n;b++){
				for(int i=a;i<=b;i++){
					if(dp[a][i]+dp[i][b]==dp[a][b]){
						sum[a][b]++;
					}
				}
				
			}
		}
		for(int a=1;a<=n;a++){
			for(int b=a+1;b<=n;b++){
				if(sum[a][b]==2){
					ans++;
				}
				
			}
		}
		
		cout<<ans<<'\n';
	}	
	return 0;
}
