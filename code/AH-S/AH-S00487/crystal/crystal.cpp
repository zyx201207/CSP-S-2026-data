#include<bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,j,k) for(int i=(j);i<=(k);i++)
inline int read(){
	int ans=0,f=1;
	char c=getchar_unlocked();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>=48&&c<=57){
		ans=ans*10+c-48;
		c=getchar_unlocked();
	}
	return ans*f;
}
const int M=500010,inf=1ll<<60;
int n,m,a[M],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	For(i,1,n) a[i]=read();
	sort(a+1,a+1+n);
	a[n+1]=inf;
	int l=1,r=0,sum=0;
	while(r<n){
		sum+=(r-l+1)*(a[r+1]-a[r]);
		r++;
		while(a[r]==a[r+1]){
			r++;
		}
		while(sum>m){
			sum-=(a[r]-a[l++]);
		}
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
}
