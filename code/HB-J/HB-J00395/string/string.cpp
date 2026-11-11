#include<bits/stdc++.h>
using namespace std;
long long n;
string a;
long long lena,sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)
		{
			a+=c;
		}
	}
	lena=a.size();
	for(int i=0;i<=lena/2;i++)
	{
		if(a[i]!=a[lena-i-1])sum++;
	}
	cout<<sum;
	return 0;
}
