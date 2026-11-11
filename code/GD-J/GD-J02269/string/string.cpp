#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
string s;
long long sum=0;
bool flag=true;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		if(c[i]!=c[i+1])
		{
			flag=false;
			break;
		}
	}
	if(flag==true)
	{
		cout<<"0";
	}
	else
	{
		cout<<sum/2;
	}
	return 0;
}
