#include <bits/stdc++.h>
using namespace std;
typedef long long LL;    
const LL N=555555;
LL b[N],dp[N],ans[N],a[N],n,m;
LL read(){
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	LL ans=0;
	while(c>='0'&&c<='9'){
		LL ss=c;
		ans=ans*10+ss-'0';
		c=getchar();
	}
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[a[i]]=i+1;
	}
	for(int i=1;i<=n;i++){
		dp[i]++;
		dp[b[a[i]]]+=dp[i];
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=dp[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
