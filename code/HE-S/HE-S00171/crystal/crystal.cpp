#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=500005;
//long long int sum,cnt,ans=0;
long long int n,m;
long long int a[MAXN],b[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+1+n);
	
	
	b[1]=0;
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		if(b[i]>m)
		{
			cout<<i-1;
			return 0;
		}
	}
	

	/* v1.0Êý¾Ý±¬Õ¨°æ 
	for(int i=1;i<=n;i++)
	{
		sum=0,cnt=0;
		for(int j=i;j>=1;j--)
		{
			if(sum+(a[i]-a[j])<=m)
			{
				sum+=a[i]-a[j];
				cnt++;
			}
			else continue;
		}
		if(cnt>=ans) ans=cnt;
		else
		{
			cout<<ans;
			return 0;
		}
	}
	*/
	return 0;
}
