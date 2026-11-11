#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int BUFSIZE=1<<20;
char ibuf[BUFSIZE],*Is=ibuf,*It=ibuf;
inline char gc(){if(Is==It)It=(Is=ibuf)+fread(ibuf,1,BUFSIZE,stdin);return Is==It?EOF:*Is++;}
inline ll read(){
	ll x=0;int f=1;char c=gc();
	while(!isdigit(c)){if(c=='-')f=-1;c=gc();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=gc();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
const int N=5e5+5;
int n,ans;
ll m,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1,l,r,mid;i<=n;i++){
		l=1,r=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(s[i]-s[mid-1]+m>=a[i]*(i-mid+1))r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-r);
	}
	write(ans);
	return 0;
}
