#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int  n;
	int a[10000];
	string b;
	cin>>n;
	string o;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b;
		for(int j=1;j<=a[i];j++)
		{
			
			o+=b;
		}
	}
	int num;
	for(int i=1;i<=n;i++)
	{
		num+=a[i];
	}
	int sum=0;
	for(int i=0;i<num/2;i++)
	{
		if(o[i]!=o[num-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


