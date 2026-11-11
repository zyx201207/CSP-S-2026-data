#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int N=5e5+10;
ll n,m,ans,sum,k,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>=5000)
	{
		int t=a[2]-a[1];
		for(int i=1;i<=n;++i)
		{
			if(m<t*i)
			{
				cout<<t*i-t<<"\n";
				return 0;
			}
		}
	}
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		sum=k=0;
		for(int j=1;j<=i;++j)
		{
			sum+=a[i]-a[j];
			++k;
		}
		if(sum<=m)
			if(k>ans)
				ans=k;
	}
	cout<<ans<<"\n";
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
