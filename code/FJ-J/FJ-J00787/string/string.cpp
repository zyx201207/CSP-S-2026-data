#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0,mid=0,s=0;
	cin>>n;
	if(n==1) 
	{
	cout<<0; 
	return 0;
    }
	for(int i=1;i<=n;i++)
	{
	cin>>a[i]>>c[i];	
	l=l+a[i];
	}
	if(n==2&&c[1]==c[2]) 
	{
	cout<<0;
	return 0;
    }
    mid=l/2;
	cout<<mid;
	return 0;
}
