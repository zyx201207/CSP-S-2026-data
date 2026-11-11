#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int ans=0;
struct Node {
	int l,r;
	char c;
}a[N],b[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int least=1;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x>>a[i].c;
		a[i].l=least;
		a[i].r=least+x-1;
		least+=x;
	}
	least--;
	for(int i=n,j=1;i>=1,j<=n;i--,j++) {
		b[i].l=(least-a[j].r+1);
		b[i].r=(least-a[j].l+1);
		b[i].c=a[j].c;
	}
	int k=(least+1)/2;
	int now=1;
	for(int i=1,j=1;i<=n&&j<=n&&now<k;) {
		int minn=min(min(a[i].r,b[j].r),k);
		if(a[i].c!=b[j].c) ans+=(minn-now+1);
		if(minn==a[i].r) i++;
		if(minn==b[j].r) j++;
		now=minn+1;
	}
	cout<<ans;
	return 0;
}

