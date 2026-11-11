#include<bits/stdc++.h> 
using namespace std;

const int N=5e3+10;
int C,T;
int n,d,a[N],dp[300][300][300],cnt=0;
void dfs(int fath,int x,int len) {
	for(int i=x+1;i<=n;i++) {
		if(a[i]-a[x]<=d) {
			dp[fath][i][len+1]+=1;
		//	cout<<fath<<' '<<x<<' '<<i<<' '<<len+1<<' '<<dp[fath][i][len+1]<<endl;
			if(len==1) {
				dfs(x,i,len+1);
			}
			else {
				dfs(fath,i,len+1);
			}
		}
	}
	return;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--) {
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		dfs(1,1,0);
	//	cout<<"//////////"<<endl;
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				for(int k=1;k<=n;k++) {
					if(dp[i][j][k]!=9) {
				//		cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
						if(dp[i][j][k]==2) {
							cnt++;
						}
					//	break;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
//0 2
// 5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
