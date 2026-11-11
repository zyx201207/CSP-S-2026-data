#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
long long a[200010],ans,n,dp[2010][2010],m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=a[i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<=m;j++){
				for(int k=1;k<i;k++){
					dp[i][j]=max(dp[i][j-1]&a[i],dp[k][j-1]&a[i]);
				}
			}
		}
//		for(int i=m;i<=n;i++){
//			cout<<dp[i][m]<<endl;
//		}
		cout<<dp[n][m];
	}
	return 0;
}
