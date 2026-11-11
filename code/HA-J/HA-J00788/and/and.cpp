#include<bits/stdc++.h>
using namespace std;
int a1,a[917887],b1,b;
string a2,a3,b2,b3;
int main()
{
	freopen("andin","r",stdin);
	freopen("andout","w",stdout);
	long long n,m,sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0)
	{
		sum=n/2;
	}
	else sum=n/2+1;
	cout<<a[sum];
}
