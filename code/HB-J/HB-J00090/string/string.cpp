#include<bits/stdc++.h>
using namespace std;
int n,flag;
long long ans;
string sen="";
struct node
{
	int l;
	char m;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char z;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].l>>a[i].m;
		if(z!=a[i].m)
		{
			flag=1;
		}
		sen+=a[i].m;
		z=a[i].m;
	}
	for(int i=0;i<=n/2;i++)
	{
		if(a[i].l!=a[n-1-i].l||a[i].m!=a[n-1-i].m)
		{
			flag=1;
			ans+=min(a[i].l,a[n-1-i].l);
		}
	}
	if(flag==0)
	{
		cout<<"0";
		return 0;
	}
	cout<<ans;
	return 0;
}
