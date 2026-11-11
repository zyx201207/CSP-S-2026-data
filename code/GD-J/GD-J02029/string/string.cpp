#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char ch[N];
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>ch[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		if(ch[l]==ch[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	printf("%lld",ans);
}
