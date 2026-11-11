#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> inline void read(T &x){
	T w=1;
	x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const int N=5e5+10;
ll a[N],n,pre[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
	int ma=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) ans=mid,r=mid-1;
			else l=mid+1;
		}
		ma=max(ma,i-ans+1);
	}	
	write(ma);
	return 0;
}
