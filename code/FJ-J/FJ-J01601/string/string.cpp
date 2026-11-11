#include<bits/stdc++.h>
using namespace std;
struct abc{
	string s1;
	long long n;
}a[200005];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		char c;
		scanf("%lld",&a[i].n);
		getchar();
		scanf("%c",&c);
		a[i].s1+=c;
	}
	/*for(i=1;i<=n;i++)
	{
		cout<<a[i].n<<' '<<a[i].s1<<endl;
	}*/
	i=1;j=n;
	while(i<j)
	{
		if(a[i].n<a[j].n)
		{
			if(a[i].s1!=a[j].s1)
			{
				ans+=a[i].n;
			}
			a[j].n-=a[i].n;
			a[i].n=0;
			i++;
		}
		else
		{
			if(a[i].n==a[j].n)
			{
				if(a[i].s1!=a[j].s1)
				{
					ans+=a[i].n;
				}
				i++;j--;
			}
			else
			{
				if(a[i].s1!=a[j].s1)
				{
					ans+=a[j].n;
				}
				a[i].n-=a[j].n;
				a[j].n=0;
				j--;
			}
		}
	}
	/*cout<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<a[i].n<<' ';
	}*/
	printf("%lld",ans);
	return 0;
}
