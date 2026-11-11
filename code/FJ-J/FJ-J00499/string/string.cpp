#include <bits/stdc++.h>
using namespace std;
long long n,a,sum,nn;
string aa,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		nn+=a;
		for(int j=0;j<a;j++)
		{
			aa+=c;
		}
	}
	for(int i=0;i<nn/2;i++)
	{
		if(aa[i]!=aa[nn-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
