#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;bool w=0;char c=getchar();
	while(c<'0'||c>'9')  c=='-'?w=1:0,c=getchar();
	while(c>='0'&&c<='9')  x=x*10+(c-48),c=getchar();
	return w?-x:x;
}
const int N=5e5+5;
int n,m,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)  a[i]=rd();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)  s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m)  r=mid;
			else  l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
// 华风夏韵，洛水天依
