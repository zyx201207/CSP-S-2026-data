#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,p=1;
	cin>>n;
	int a[200005];
	char c[200005];
	string s;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	for(int i=0;i<n;)
	{
		if(c[i]!=c[n-i-p])
		{
			ans+=min(a[i],a[n-i-p]);
			if(a[i]>a[n-i-p])
			{
				a[i]-=a[n-i-p];
				a[n-i-p]=0;
				p++;
			}
			else if(a[i]<a[n-i-p])
			{
				a[n-i-p]-=a[i];
				a[i]=0;
				p--;
				i++;
			}
			else
			{
				a[i]=0;
				a[n-i-p]-=a[i];
				i++;
			}
		}
		else
		{
			break;
		}
		
	}
	cout<<ans;
}


