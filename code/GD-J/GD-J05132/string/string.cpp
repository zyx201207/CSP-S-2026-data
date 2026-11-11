#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+20;
struct node
{
	ll x;
	char c;
}a[N];
ll n,m,i,j,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	i=1;
	j=n;
	while(i<=j)
	{
		if(a[i].x==a[j].x)
		{
			if(a[i].c!=a[j].c)
			{
				ans+=a[i].x;
			}
			i++;
			j--;
		}
		else if(a[i].x>a[j].x)
		{
			a[i].x-=a[j].x;
			if(a[i].c!=a[j].c)
			{
				ans+=a[j].x;
			}
			j--;
		}
		else
		{
			a[j].x-=a[i].x;
			if(a[i].c!=a[j].c)
			{
				ans+=a[i].x;
			}
			i++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
