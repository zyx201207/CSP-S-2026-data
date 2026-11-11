#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> PII;

ll read() {
	ll n=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		n=(n<<1)+(n<<3)+ch-'0';
		ch=getchar();
	}
	if(f==1) return n;
	return -n;
}

void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar((x%10)+'0');
}

//========================================//

const int N=5e5+7;

int n;
ll m;
ll a[N];
ll pre[N];
int ans;

//========================================//

void input() {
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
}

void work() {
	ans=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		int l=1,r=i;
		int mid,res=i;
		while(l<=r) {
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m) {
				res=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	write(ans);
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	input();
	work();
	return 0;
}
