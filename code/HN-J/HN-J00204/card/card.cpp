#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000000];
int b[2000000];
int c[1000000];
int s;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++)
{
	cin>>a[i];
	c[i]=a[i];
}
for(int i=0;i<n;i++)
{
	for(int f=0;f<n;f++)c[i]=a[i];
	for(int j=i;j<n;j++)
	{
		for(int q=i+1;q<n;q++)
		{
			if(c[q]==c[j]&&c[q]!=0)
			{
				for(int e=j;e<q;e++)c[e]=0;
			}
		}	
	}
	for(int w=i;w<n;w++)
	{
		if(c[w]!=0)
		{
			int e=c[w];
			b[e]++;
			if(e>s)s=e;
		}
	}
}
for(int i=1;i<=s;i++)
cout<<b[i]<<" ";
return 0;
} 
