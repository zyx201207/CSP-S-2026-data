#include<bits/stdc++.h>
using namespace std;
string str1;
int n,a[200010];
char ch[200010];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		cin>>ch[i];
	}
	int q=n-1;
	for(int i=0;i<n/2;i++)
	{
		if(ch[i]!=ch[q])
		{
			if(a[i]==a[q])
				ans+=a[q];
			else if(max(a[i],a[q])==a[i])
			{
				if(ch[q--]==ch[i])
					ans+=a[q];
				else
				{
					ans+=a[i];
					a[q--]-=a[i]=a[q];
				}
			}
			else
			{
				if(ch[q]==ch[i++])
					ans+=a[i];
				else
				{
					ans+=a[q];
				}
			}
		}
		q--;
	}
	printf("%lld",ans);
	return 0;
}
