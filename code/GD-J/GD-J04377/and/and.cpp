#include<bits/stdc++.h>
#define int long long
#define lowbit(a) a&(-a)
using namespace std;
const int N=2e5+5;
int n,m,a[N],dp[N],maxx;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0') x=x*10+(c-'0'),c=getchar();
	return f*x;
}
//void add(int x,int k){
//	while(x<=n) c[x]=max(c[x],k),x+=lowbit(x);
//}
//int ask(int x){
//	int ans=0;
//	while(x){
//		ans=max(ans,c[x]);
//		x-=lowbit(x);
//	}
//	return ans;
//}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[0]=4294967295;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(dp[j-1]!=0)dp[j]=max(dp[j],(dp[j-1]&a[i]));
		}
	}
	cout<<dp[m];
	return 0;
} 
