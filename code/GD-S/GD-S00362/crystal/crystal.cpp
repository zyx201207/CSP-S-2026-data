#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],sum[500005],s,ans;
bool flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1])flag=0;
	}
	if(flag){cout<<n;return 0;}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(ll i=1,j=1;i<=n;i++){
		s+=(i-j)*(a[i]-a[i-1]);
		while(s>m&&i>=j)s-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
