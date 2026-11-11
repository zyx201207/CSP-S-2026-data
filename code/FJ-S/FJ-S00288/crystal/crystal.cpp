#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define il inline
#define re register int
#define rl register ll
#define gc getchar
using namespace std;
const int MN=5e5+5;
ll n,m,a[MN],ans,s[MN];
il ll read(){ll x=0,f=1;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return x*f;}
il void write(rl x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(re i=1; i<=n; ++i) a[i]=read();
	sort(a+1,a+1+n);
	for(re i=1; i<=n; ++i) s[i]=s[i-1]+a[i];
	ll l=1;
	for(rl i=1; i<=n; ++i){
		while(a[i]*(i-l+1)-s[i]+s[l-1]>m&&l<=n) ++l;
		ans=max(ans,i-l+1);
	}
	write(ans);putchar('\n');
	return 0;
}//261031

