#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[200010];
bool cmp (int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m,sum=0,cnt=0;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	if(a[i]>cnt)
	{
		cnt=a[i];
	}
}
if(m==1)
{
	cout<<cnt;
	return 0;
}
sort(a+1,a+n+1,cmp);
for(int i=1;i<=n;i++)
{
	if(a[i]==a[i+1]) 
	{
		cout<<a[i];
		return 0;
	}
}
sum=a[1];
for(int i=1;i<=m-1;i++)
{
	sum=sum|a[i+1]; 
}cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
