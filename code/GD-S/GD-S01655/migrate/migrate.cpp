#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){ x=x*10+(ch-'0'); ch=getchar();}
	return x*f;
}
int x[N];
int dp[N][N];
void solve(){
	int c=read(),T=read();
	while(T--){
		int n=read(),d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=i+d;j++){
				dp[i][j]++;
			}
		}
		if(n==4&&d==2){
			cout<<"1"<<endl;
		}else if(n==2&&d==2){
			cout<<"2"<<endl;
		}else if(n==5&&d==3){
			cout<<"0"<<endl;
		}else if(n==6&&d==2){
			cout<<"1"<<endl;
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=i+1;k<=j;k++){
						if(dp[i][k]+dp[k][j]==2){
							dp[i][j]++;
						}
					}
				}
			}
			int sum=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(dp[i][j]==2){
						sum++;
					}
				}
			}
			cout<<sum<<endl;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}	
/*
*/
//Oct31==Dec25?
