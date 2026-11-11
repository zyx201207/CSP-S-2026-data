#include <iostream>
#include <string>
#define int long long
using namespace std;
int n,ans,now,a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	now=n;
	for(int i=1;i<=n;i++)
	{
		int num=a[i];
		while(num>0)
		{
			if(now<=i)
			{
				cout<<ans;
				return 0;
			}
			if(a[now]>num)
			{
				if(c[now]!=c[i])
					ans+=num;
				a[now]-=num;
				num=0;
			}
			else
			{
				num-=a[now];
				if(c[now]!=c[i])
					ans+=a[now];
				now--;
			}
		}
	}
	return 0;
}
