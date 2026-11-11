#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){write(-x); return;}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
const int N=5e5+5;
int n,m;
int a[N],sum[N];
int solve(int k){
	int l=1,r=k,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[k]*(k-mid)-(sum[k-1]-sum[mid-1])<=m){
			ans=mid; r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=2;i<=n;i++) ans=max(ans,i-solve(i)+1);
	write(ans);
	return 0;
}
