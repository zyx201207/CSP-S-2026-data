#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,m,a[N],pre[N],ans;
bool check(int l,int r) {
	int c=pre[r]-pre[l-1];
	if(a[r]*(r-l+1)-c<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=a[i]+pre[i-1];
	for(int i=1;i<=n;i++) {
		int l=i,r=n;
		while(l<r) {
			int mid=(l+r+1)/2;
			if(check(i,mid)) {
				ans=max(ans,mid-i+1);
				l=mid;
			}
			else r=mid-1;
		}
	}
	cout<<ans;
}
/*
5 5s
1 2 4 8 9
5 8
-3 -1 2 2 7
s
上一行我喜欢你！！！
30min T1通过
2+1/4h T2通过，锁定NOIP
预期208ptsAwA
*/
