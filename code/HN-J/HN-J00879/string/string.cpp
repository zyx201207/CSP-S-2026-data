#include<bits/stdc++.h>
using namespace std;
int p;
char q,a[20001];
int n=0,k=0,num=0,len=0,lenl=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		cin>>q;
		for(int j=1;j<=p;j++)
		{
			a[j+len]=q;
		}
		len+=p;
	}
	if(len%2==0)
	{
		lenl=len;
	}
	else
	{
		lenl=len+1;
	}
	for(int i=1;i<=len/2;i++)
	{
		if(a[i]==a[len-i+1])
		{
			continue;
		} 
		else
		{
			a[len-i+1]=a[i];
			num++;
		}
	}
	cout<<num;
	return 0;
}
