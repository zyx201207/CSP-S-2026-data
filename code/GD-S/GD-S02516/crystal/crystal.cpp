#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,r,t,s,i,a[500005],q[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
		l=1;
		r=i;
		while(l<=r){
			t=l+r>>1;
			if((i-t+1)*a[i]-(q[i]-q[t-1])<=m)r=t-1;
			else l=t+1;
		}
		s=max(s,i-r);
	}
	cout<<s;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
