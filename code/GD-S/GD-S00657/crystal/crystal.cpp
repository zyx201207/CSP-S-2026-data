#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int n;
long long m;
int a[N];
int d[N];

long long ans=1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++)
	{
		long long cnt=m,an=1;
		
		for(int j=i-1;j>=1;j--)
		{
			if(cnt>=a[i]-a[j])
			{
				cnt-=a[i]-a[j];
				an++;
				ans=max(ans,an);
			}
			else if(cnt<a[i]-a[j])
			{
				break;
			}
		}
	}

	cout<<ans;	
}
	
	
	
	
 
