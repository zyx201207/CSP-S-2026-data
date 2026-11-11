#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,a[200006];
	ll number=0;
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]==a[i])
			{
				number=max(number,a[i]);
			}
		}
	}
	cout<<number;
	return 0;
}
