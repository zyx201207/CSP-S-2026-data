#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)  scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int left=1;
	for(int right=2;right<=n;right++){
		m-=(a[right]-a[right-1])*(right-left);
		while(m<0)  m+=a[right]-a[left],left++;
		ans=max(ans,right-left+1);
	}
	cout<<ans;
	return 0;
}
