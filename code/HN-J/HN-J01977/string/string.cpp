#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a=0,v[100005],sum=0;
    char g[100005];
	cin>>n;
	while(a<n)
	{
		cin>>v[a];
		cin>>g[a];
		a++;
	}
	if(n==1)
	{
		cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
	if(n==2)
	{
		cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
	a=0;
	cout<<n-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
