#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string,in","r",stdin);
	freopen("string,out","w",stdout);
	char b[30];
	long long n,i,s,a[200005],k=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]%2!=0)
		{
			cout<<"0";
			k=1;
			break;
		}
		else
		{
			s+=a[i];
		}
	}
	if(k==0)
	{
		s=s/2;
		cout<<s;
	}
}
