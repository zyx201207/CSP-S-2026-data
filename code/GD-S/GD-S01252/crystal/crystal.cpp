#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1,num=1,ptr=1;
	for(int i=2;i<=n;i++) {
		if((a[i]-a[i-1])*num<=m) {
			m-=(a[i]-a[i-1])*num;
			num++;
		}else {
			while(m<(a[i]-a[i-1])*num) {
				m+=a[i-1]-a[ptr];
				ptr++,num--;
			}
			m-=(a[i]-a[i-1])*num;
			num++;
		}
		ans=max(ans,num);
	} 
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
