#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],s=0,q=0;
char c[10000],d[10000];
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			d[q+j]=c[i];
		 } 
		 q+=a[i];
	 } 
	
	for(int i=1;i<=q/2;i++)
	{
		if(d[i]-'a'!=d[q-i+1]-'a') s++;	
	}
	cout<<s;
	return 0;

}
