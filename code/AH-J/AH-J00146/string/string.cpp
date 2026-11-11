#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005];
char b[200005];
void so1()
{
	ll x,sum=0;
	char c;
	string s;
	while(n--)
	{
		cin>>x>>c;
		while(x--)
		{
			s+=c;
		}
	}
	ll i=0,j=s.size()-1;
	while(i<=j)
	{
		sum+=(s[i++]!=s[j--]);
	}
	cout<<sum;
}
void so2()
{
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	ll i=1,j=n,s=0;
	while(i<j)
	{
		if(b[i]==b[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j--];
			}
			else if(a[i]<a[j])
			{
				a[j]-=a[i++];
			}
			else
			{
				i++,j--;
			}
		}
		else
		{
			if(a[i]>a[j])
			{
				s+=a[j];
				a[i]-=a[j--];
			}
			else if(a[i]<a[j])
			{
				s+=a[i];
				a[j]-=a[i++];
			}
			else
			{
				s+=a[i++];
				j--;
			}
		}
	}
	cout<<s;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<=10)so1();
	else so2();
	return 0;
}
