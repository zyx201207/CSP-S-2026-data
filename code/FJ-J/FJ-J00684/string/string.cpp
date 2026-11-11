#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P 200010
ll s = 0;
ll xia = 1;
bool jia = true;
struct f
{
	ll m;
	char q;
};
f a[P];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	for(ll i = 1;i<=n;i++)
	{
		cin>>a[i].m>>a[i].q;
		if(i!=1&&a[i-1].q!=a[i].q&&jia==true)
		{
			jia = false;
		}
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(jia==true)
	{
		cout<<0<<endl;
		return 0;
	}
	for(ll i = 1;i<=n/2;i++)
	{
		if(a[xia].m==a[n-xia+1].m&&a[xia].q!=a[n-xia+1].q)
		{
			s = s+a[xia].m;
		}
		else if(a[xia].m!=a[n-xia+1].m&&a[xia].q==a[n-xia+1].q) 
		{
			if(a[xia].m>a[n-xia+1].m)
			{
				if(a[n-xia].q==a[xia].q)
				{
					a[n-xia].m -= (a[xia].m-a[n-xia+1].m);
				}
				else
				{
					s += (a[xia].m-a[n-xia+1].m);
					a[n-xia].m -= (a[xia].m-a[n-xia+1].m);
				}
			}
			else
			{
				if(a[xia+1].q==a[xia].q)
				{
					a[xia+1].m -= (a[n-xia+1].m-a[xia].m);
				}
				else
				{
					s += (a[n-xia+1].m-a[xia].m);
					a[xia+1].m -= (a[n-xia+1].m-a[xia].m);
				}
			}
		}
		else if(a[xia].m!=a[n-xia+1].m&&a[xia].q!=a[n-xia+1].q)
		{
			if(a[xia].m<a[n-xia+1].m)//½ÏÐ¡Öµ
			{
				s += a[xia].m;
				if(a[xia+1].q==a[n-xia+1].q)
				{
					a[xia+1].m -= a[n-xia+1].m-a[xia].m;
				}
				else
				{
					a[xia+1].m -= a[n-xia+1].m-a[xia].m;
					s += a[n-xia+1].m-a[xia].m;
				}
			} 
			else
			{
				s += a[n-xia+1].m;
				if(a[n-xia+1].q==a[n-xia].q)
				{
					a[n-xia].m -= a[xia].m-a[n-xia+1].m;
				}
				else
				{
					a[n-xia].m -= a[xia].m-a[n-xia+1].m;
					s += a[xia].m-a[n-xia+1].m;
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;
}

