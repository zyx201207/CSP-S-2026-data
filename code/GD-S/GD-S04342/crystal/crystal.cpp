#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],ans;
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j>=1;j--)
		{
			sum+=abs(a[i]-a[j]);
			//cout<<abs(a[i]-a[j])<<" "<<sum<<endl;
		}
		if(sum==m)
		{
			ans=i;
			for(int k=i+1;k<=n;k++)
			{
				if(a[k]==a[i]) ans++;
			}
			cout<<ans<<endl;
			break;
		}
	}
	return 0;
}
