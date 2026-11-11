#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace IO{
	template<typename T>void read(T &x){short f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();x*=f;return;}
	template<typename T>void out_(T x){if(x>9) out_(x/10);putchar(x%10+'0');return;}
	template<typename T>void out(T x){if(x<0) putchar('-'),x=-x;out_(x),putchar(' ');return;}
	void endl(){putchar('\n');return;}
}using namespace IO;
const int N=1e6+5;
int n,m,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	out(ans);
	return 0;
}
