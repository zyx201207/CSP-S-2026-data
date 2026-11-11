#include<iostream>
#include<algorithm>
using namespace std;
unsigned long long n,m,a[500005],ans=-1;
bool b=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//if(a[i]!=i)b=0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		long long x=0,y=m,j=i-1,sum=1;
		while(y>=a[i]-a[j]&&j>=1)
		{
			sum++;
			y-=a[i]-a[j];
			j--;
			//cout<<y<<' ';
		}
		//cout<<sum<<endl;
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
