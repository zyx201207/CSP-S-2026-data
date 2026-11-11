#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a,b,d,c[200000],e[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		cin>>c[i];
	}
	sort(c,c+a);
	for(int i=0;i<b;i++)
	{
		for(int j=1;j<a-1;j++)
		{
			if((c[a-1]&c[j])>(c[a-1]&c[j-1]))
			{
				d=j;
			}
		}
		e[i]=c[d];
		c[d]=0;
	}
	a=e[0];
	for(;b;b--)
	{
		if(e[b]!=0)
		{
			a=(a&e[b]);
		}
	}
	cout<<a;
	return 0;
} 
