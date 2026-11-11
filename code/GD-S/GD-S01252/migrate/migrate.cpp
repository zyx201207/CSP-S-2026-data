#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,a[N],f[N],c[N];
void solve() {
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) c[j]=f[j]=0;
		f[i]=0;
		int sum=1,ptr=i,cur=i;//和ptr相同的最右边 
		c[i]=1;
		for(int j=i+1;j<=n;j++) {
			while(ptr<j&&a[j]-a[ptr]>d) sum-=c[ptr],ptr++;
			if(ptr==j) break;
//			while(cur<ptr) sum+=c[cur],cur++;
			while(cur+1<j&&f[cur+1]<=f[ptr]) {
				cur++;
				sum+=c[cur]; 
			}
			f[j]=f[ptr]+1;
			c[j]=sum;
			if(sum==2) ans++;
		}
	}
	cout<<ans<<"\n";
} 
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 3
0 3 6 7 8 9 10 11 14 17
ans:9
*/
