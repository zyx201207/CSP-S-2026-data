#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+5;
LL n;
char c[N];
LL a[N],cnt;
LL ans,num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char ch1;
	for(LL i=1;i<=n;i++){
		cin>>num>>ch1;
		if(ch1==c[cnt]) a[cnt]+=num;
		else{
			a[++cnt]=num;
			c[cnt]=ch1;
		}
		
	}
	for(LL i=1;i<=cnt/2;i++){
		if(c[i]==c[1+n-i]) ans+=abs(a[1+n-i]-a[i]);
		else ans+=max(a[1+n-i],a[i]);
	}
	cout<<ans;
	return 0;
}
