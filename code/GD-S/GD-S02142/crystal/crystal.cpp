#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int maxn=5e5+5;
const i64 inf=numeric_limits<i64>::max();

int main();

int n;
i64 m;
i64 a[maxn];

int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
#ifndef local
	freopen("crystal.in" ,"r",stdin ),
	freopen("crystal.out","w",stdout);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	int j=1;
	for(int i=1;i<=n;i++){
		m-=(i-j)*(a[i]-a[i-1]);
		while(m<0)m+=a[i]-a[j++];
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
