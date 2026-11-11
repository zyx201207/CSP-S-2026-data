#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string c[200005],c_;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			c_+=c[i];
		}
	}
	int g=n;
	int num=0;
	for(int i=0;i<=floor(n/2);i++)
	{
		if(c_[i]!=c_[g])
		{
			num++;
		 } 
		g--;
	}
	cout<<num;
	return 0;
}
