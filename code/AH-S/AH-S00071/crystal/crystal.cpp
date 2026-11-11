#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;long long m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int L=1,R=1,ans=0;
	long long now=0;
	for(;R<=n;R++){
		now+=(R-L)*(a[R]-a[R-1]);
		while(now>m) L++,now-=(a[R]-a[L-1]);
		ans=max(ans,R-L+1);
	}
	cout<<ans;
	return 0;
}
