// 2:40

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define siz(x) ((int)(x).size())
#define L(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,r,l) for(int i=(r);i>=(l);i--)
#define ve(x) vector<x>
#define x first
#define y second
#define me(x,v) memset(x,v,sizeof(x))
#define wr(...) printf(__VA_ARGS__)

using sint =signed;
using ll =long long;

char gc() {
	return getchar();
}
void pc(char c) {
	putchar(c);
}
int rd() {
	int sgn=0,ret=0,c=0;
	while(c<'0'||c>'9') {
		sgn|=(c=='-');
		c=gc();
	}
	while(c>='0'&&c<='9') {
		ret=ret*10+c-'0';
		c=gc();
	}
	return sgn?-ret:ret;
}

constexpr int N=1e6+7;

int n,m;
int a[N],sum[N];

bool check(int x,int y) {
	return a[y]*(y-x+1)-(sum[y]-sum[x-1])<=m;
}

sint main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=rd(),m=rd();
	L(i,1,n) {
		a[i]=rd();
	}
	sort(a+1,a+1+n);
	L(i,1,n) {
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	L(i,1,n) {
		int l=1,r=i,res=i;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(mid,i)) {
				res=mid,r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	wr("%lld\n",ans);
	return 0;
}
