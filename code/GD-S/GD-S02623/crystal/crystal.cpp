#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define x first
#define y second
inline int in() {
	static char ch;
	static int a,f;
	ch=getchar();
	a=0,f=1;
	for(; !isdigit(ch); ch=getchar())if(ch=='-')f=-1;
	for(; isdigit(ch); ch=getchar())a=(a<<1)+(a<<3)+ch-'0';
	return a*f;
}
const int N=5e5+100;
int a[N],n=0,m=0,ans=0;
bool check(int num) {
	static int sum;
	sum=0;
	for(int i=1; i<=num; i++)sum+=a[num]-a[i];
	if(sum<m)return 1;
	for(int i=num+1; i<=n; i++) {
		sum=sum+
			num*(a[i]-a[i-1])
			-(a[i]-a[i-num]);
		if(sum<m)return 1;
	}
	return 0;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in();
	m=in();
	for(int i=1; i<=n; i++)a[i]=in();
	sort(a+1,a+n+1);
	int l=1,r=n,mid;
	while(l<=r) {
		mid=(l+r)>>1;
		if(check(mid)) {
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	cout<<ans;
	return 0;
}
