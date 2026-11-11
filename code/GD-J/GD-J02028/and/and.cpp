#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
inline int read(){
	int f=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
} 
int dp[3][maxn],a[maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dp[i&1][1]=max(dp[1-i&1][1],a[i]);
		for(int j=2;j<=m;j++){
			dp[i&1][j]=max(dp[1-i&1][j],dp[1-i&1][j-1]&a[i]);
		}
	}
	cout<<dp[n&1][m];
	return 0;
}
