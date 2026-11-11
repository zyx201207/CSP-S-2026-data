#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=2e5+10; 
ll n,a[N],ans=0,cnt=0,mid=0;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		mid+=a[i];
	}
	ll i=1,j=n;
	while(cnt < mid/2)
	{
		if(a[i] -a[j] > 0)
		{
			if(c[i] != c[j])
			{
				ans+=a[j];
			}
			a[i]-=a[j];
			cnt+=a[j];
			j--;
		}
		else if(a[i] -a[j] < 0)
		{
			if(c[i] != c[j])
			{
				ans+=a[i];
			}
			a[j]-=a[i];
			cnt+=a[i];
			i++;
		}
		else
		{
			if(c[i] != c[j])
			{
				ans+=a[i];
			}
			cnt+=a[i];
			i++;
			j--;
		}
	}
	cout << ans << endl;
	return 0;
}
