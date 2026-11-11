#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],ans[300010],as;
vector<ll> arr;
bool fnd(ll fndn)
{
	for(int i=0;i<as;i++)
	{
		if(arr[i]==fndn)
		{
			return 1;
		}
	}
	return 0;
}
ll f2(ll fndn)
{
	for(int i=as-1;i>=0;i--)
	{
		if(arr[i]==fndn)
		{
			return i;
		}
	}
}
void era(ll ind)
{
	for(int i=ind;i<as-1;i++)
	{
		arr[i]=arr[i+1];
	}
	as--;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		arr.clear();
		as=0;
		for(int j=i;j<=n;j++)
		{
			if(fnd(a[j])==0)
			{
				arr.push_back(a[j]);
				as++;
			}
			else
			{
				ll t=f2(a[j]);
				while(t<as)
				{
					era(t);
				}
				arr[t+1]=a[j];
				as++;
			}
		}
		for(int j=0;j<as;j++)
		{
			ans[arr[j]]++;
//			cout << arr[j] << " ";
		}
//		cout << "\n";
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",ans[i]);
	}
	printf("\n");
	return 0;
}
