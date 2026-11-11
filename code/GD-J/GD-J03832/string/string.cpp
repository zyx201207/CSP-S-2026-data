#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
int a[N];
char s[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>s[i];
	}
	for(int i=1,j=n;i<=n;)
	{
		if(i>=j) break;
		if(s[i]==s[j])
		{
			if(a[i]==a[j])
			{
				i++,j--;
			}
			else if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else
			{
				a[j]-=a[i];
				i++;
			}
		}
		else
		{
			if(a[i]==a[j])
			{
				ans+=a[i];
				i++,j--;
			}
			else if(a[i]>a[j])
			{
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}
			else
			{
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}

