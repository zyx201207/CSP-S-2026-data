#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans=0;
struct qwe
{
	ll m;
	char ch;
}a[200050];
int main()
{
	freopen("string.in","c",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].m>>a[i].ch;
	for(int i=1,j=n;i<=j;)
	{
		if(a[i].m<a[j].m)
		{
			if(a[i].ch!=a[j].ch)
				ans+=a[i].m;
			a[j].m-=a[i].m;
			i++;
		}
		if(a[i].m>a[j].m)
		{
			if(a[i].ch!=a[j].ch)
				ans+=a[j].m;
			a[i].m-=a[j].m;
			j--;
		}
		if(a[i].m==a[j].m)
		{
			if(a[i].ch!=a[j].ch)
				ans+=a[j].m;
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
