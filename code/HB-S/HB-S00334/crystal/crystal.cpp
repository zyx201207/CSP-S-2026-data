#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans=1;
int a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i+1]-a[i];
		cnt+=ans*s[i];
		ans++;
		if(cnt>=m)break;
	}	
	cout<<ans;
	return 0;
}	
