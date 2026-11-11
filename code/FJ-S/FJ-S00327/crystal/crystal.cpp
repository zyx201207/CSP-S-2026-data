#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=5e5+5;
ll n,m,a[N],b[N],A=1;
ll R(){ll a=0,f=1;char c=getchar();for(;c<48||c>57;c=getchar())f=c=='-'?-1:1;
	for(;c>47&&c<58;c=getchar())a=(a<<1)+(a<<3)+(c^48);return a*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=R(),m=R();for(int i=1;i<=n;i++)a[i]=R();sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1,l=1;i<=n;i++){
		while(b[i]-b[l-1]+m<a[i]*(i-l+1))l++;
		A=max(A,i-l+1ll);
	}printf("%lld\n",A);
	return 0;
}/*
14:38
18:07
*/
