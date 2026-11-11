#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500002],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++){
		sum+=1ll*(i-j)*(a[i]-a[i-1]);
		while(sum>m)sum+=a[j++]-a[i];
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
