#include<bits/stdc++.h>
using namespace std;
char z[200000003];
char zb[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,zs=0;
	cin>>n;
	int r=1,l=1;
	while(n--)
	{
		int a;
		char s;
		cin>>a;
		cin>>s;
		int f=s-'a';
		for(int i=l;i<=l+a;i++)
		{
			z[i]=zb[f];
		}
		l+=a;
	}
	l-=1;
	int ds=l;
	for(int i=1;i<=ds/2;i++)
	{
		if(z[r]!=z[l])
		{
			zs+=1;
		}
		r+=1;
		l-=1;
	}
	cout<<zs;
	return 0;
} 
