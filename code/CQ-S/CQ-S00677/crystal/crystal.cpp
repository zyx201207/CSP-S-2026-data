#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int Maxn=5e5+5;
int n,m,a[Maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	int ans=0,p=1,sum=0;
	for(int i=1;i<=n;i++){
		sum+=(i-p)*(a[i]-a[i-1]);
		while(p<i&&sum>m)sum-=(a[i]-a[p]),p++;
		ans=max(ans,i-p+1);
//		printf("%d:[%d,%d]\n",i,p,sum);
	}
	printf("%lld\n",ans);
	return 0;
}//14:35
/*
5 5
1 2 4 8 9
*/
