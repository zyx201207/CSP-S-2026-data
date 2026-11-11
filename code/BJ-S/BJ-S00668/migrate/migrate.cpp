#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2000000;
int caseid,T,n,d,x[MAXN+10],ans;
int dp[310][310],/*j move*/qzhx[310][310],l,r;
int lind[MAXN+10],rind[MAXN+10];
bool used[310][310];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>caseid>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(caseid==11 || caseid==12){
			int l=x[2]-x[1],t=d/l;
			if(t>=2){
				cout<<max(0ll,n-2*t+1)<<endl;
			}else{
				cout<<0<<endl;
			}
		}else if(caseid==13 || caseid==14){
				
		}else if(15<=caseid && caseid<=18){
			
		}else{
			l=1,r=n;
			for(int i=1;i<=n;i++){
				while(l<i && x[l]<x[i]-d) l++;
				lind[i]=l; 
			}
			for(int i=n;i>=1;i--){
				while(r>i && x[r]>x[i]+d) r--;
				rind[i]=r; 
			}
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=0,qzhx[i][j]=0,used[i][j]=0;
			ans=0;
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(k==1){
							if(x[j]-x[i]<=d) dp[i][j]=1;
						}else{
							dp[i][j]=qzhx[i][j-1]-qzhx[i][max(i+1,lind[j])-1];
						}
					}
				}
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(!used[i][j] && dp[i][j]>0){
							used[i][j]=1;
							if(dp[i][j]==2) ans++;
						}
					}
				}
				for(int i=1;i<=n;i++){
					qzhx[i][i+1]=dp[i][i+1];
					for(int j=i+2;j<=n;j++){
						qzhx[i][j]=qzhx[i][j-1]+dp[i][j];
					}
				}
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
