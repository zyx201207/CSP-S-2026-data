#include<bits/stdc++.h>
using namespace std;
char inc;
int ina,n;
unsigned long long ans;
struct pas
{
	int n;
	char c;
}pas[300010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>pas[i].n>>pas[i].c;
	}
	//for(int i=1;i<=n;i++)
	//{
	//	cout<<pas[i].n<<pas[i].c<<endl;
	//}
	for(int i=1,j=n;i<j;)
	{
		if(pas[i].n>pas[j].n)
		{
			//cout<<1<<endl;
			if(pas[i].c!=pas[j].c)
			{
				ans+=pas[j].n;
			}
			//cout<<pas[i].n<<pas[i].c<<pas[j].n<<pas[j].c<<endl;
			pas[i].n-=pas[j].n;
			//cout<<pas[i].n<<pas[i].c<<pas[j].n<<pas[j].c<<endl;
			j--;
		}
		if(pas[i].n<=pas[j].n)
		{
			//cout<<2<<endl;
			if(pas[i].c!=pas[j].c)
			{
				ans+=pas[i].n;
			}
			//cout<<pas[i].n<<pas[i].c<<pas[j].n<<pas[j].c<<endl;
			pas[j].n-=pas[i].n;
			//cout<<pas[i].n<<pas[i].c<<pas[j].n<<pas[j].c<<endl;
			i++;
		}
		/*
		else
		{
			if(pas[i].c!=pas[j].c)
			{
				ans+=pas[i].n;
			}
			cout<<pas[i].n<<pas[i].c<<pas[j].n<<pas[j].c<<endl;
			pas[j].n=0;
			pas[i].n=0;
			cout<<pas[i].n<<pas[i].c<<pas[j].n<<pas[j].c<<endl;
			i++;
			j--;
		}*/
		//cout<<ans<<' '<<i<<' '<<j<<endl;
	}
	cout<<ans;
	return 0;
}
