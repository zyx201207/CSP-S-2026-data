#include<iostream>
#include<cstdio>
using namespace std;
int a[1000000],m,n,b[1000000];
int two(int k)
{
	int yu,temp=0,f=1;
	while(k!=0)
	{
		yu=k%2;
		k=k/2;
		temp=temp+yu*f;
		f*=10;
	}
	return temp;
}
int yu(int a,int b)
{
	int sum;
	for(int p=1;p<=20;p++)
	{
		if(a%10==b%10&&b%10==1)
			sum++;
		a/=10;
		b/=10;
	}
	return sum;
}
int search(int k,int max)
{
	for(int i=1;i<=n;i++)
	{
		b[k]=a[i];
		if(k==m)
		{
			int y=b[1];
			for(int g=2;g<=m;g++)
			{
				y=yu(two(y),two(b[g]));
			}
			if(y>max)
				max=y;
		}
		search(k+1,max);
		b[k]=0;
	}
	return max;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<search(1,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
