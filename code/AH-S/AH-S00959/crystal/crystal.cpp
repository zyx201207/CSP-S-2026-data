#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n,k,a[N],l=1,p,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p+=(i-l)*(a[i]-a[i-1]);
		while(p>k&&l<i)
			p-=(a[i]-a[l++]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
