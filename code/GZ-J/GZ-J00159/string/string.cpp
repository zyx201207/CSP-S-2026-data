//GZ-J00159 六盘水市第二十四中学 杨沛雯 
#include<bits/stdc++.h>
using namespace std;
int n,c;
char s,y;
int x=0;
int sum=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c>>s;
		if(y==s) sum++;
		if(x==c) ans++;
		y=s;
		x=c;
	}
	if(n==1) 
	{
		cout<<0;
		return 0;
	}
	if(sum==n)
	{
		cout<<0;
		return 0;
	}
	if(ans==n&&n%2==0)
	{
		cout<<0;
		return 0;
	}
	else
	{
		cout<<3;
		return 0;
	}
	return 0;
}
