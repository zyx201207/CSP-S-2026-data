#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=f;
	return;
}
template<typename T>
inline void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
#define fi first
#define se second
#define chkmin(x,y) (x=min(x,y))
#define chkmax(x,y) (x=max(x,y))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,int> PLI;
const int N=5e5+5;
int n,ans;
ll a[N],m;
void solve(){
	read(n),read(m);
	for(int i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+n+1);
	ll s=0;
	for(int r=1,l=1;r<=n;++r){
		while(l<=n&&1ll*(r-l)*a[r]-s>m) s-=a[l],++l;
		chkmax(ans,r-l+1),s+=a[r];
	}
	write(ans);
	putchar('\n');
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c=1,T=1;
	while(T--) solve();
	return 0;
} 
