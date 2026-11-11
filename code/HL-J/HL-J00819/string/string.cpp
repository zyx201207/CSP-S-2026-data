#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node
{
	ll id;
	char x;
}a[10000000];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].id>>a[i].x;
	string s={};
	for(int i=1;i<=a[i].id;i++)
	{
		s+=a[i].x;
	}
		
	return 0;
}