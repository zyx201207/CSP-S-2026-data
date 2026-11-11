#include<bits/stdc++.h>
using namespace std;
char s[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",std);
	int n,p;
	char b,y;
	int a,c=0,pd=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(i>=1)
		{
			if(b!=y)
			{
			pd=0;	
			}
		}
		for(int j=c;j<c+a;j++)
		{
			s[j]=b;
		}
		c=a;
		y=b;
	}
	if(pd==1)
	{
		cout<<0;
		return 0;
	}
	
	return 0;
} 
