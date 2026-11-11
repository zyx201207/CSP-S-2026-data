#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N];
int gets(int l,int r) {return s[r]-s[l-1];}
int calc(int l,int r) {
	return a[r]*(r-l+1)-gets(l,r);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++) {
		int l=1,r=i,j=0;
		while(l<=r) {
			int mid=(l+r)/2;
			if(calc(mid,i)<=m) j=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
} 
/*
5 5
1 2 4 8 9

3
4
3845
315275

*/
