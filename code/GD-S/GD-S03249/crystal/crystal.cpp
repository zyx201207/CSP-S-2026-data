#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll m,a[N],cnt;
int n,ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%lld",a+i);
	sort(a+1,a+1+n);
	int l=1;
	for(int i=1; i<=n; i++) {
		cnt+=(a[i]-a[i-1])*(i-l);
		while(l<i && cnt>m) {
			cnt-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
14:43
*/
