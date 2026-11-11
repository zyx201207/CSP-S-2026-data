#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
using namespace std;
string a;
char b;
int n,m,t;
long long ans,sum;
int main()
{
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			cin>>n;
			cin>>b;	
			for(int i=1;i<=n;i++)
			{
				a[++t]=b;
				ans++;
			}	
		}
		if(ans%2!=0)
		{
			for(int i=1;i<=(ans-1)/2;i++)
				if(a[i]!=a[ans+1-i])
					sum++;
		}
		if(ans%2==0)
		{
			for(int i=1;i<=(ans-1)/2;i++)
				if(a[i]!=a[ans+1-i])
					sum++;
		}	
		cout<<sum;		
		return 0;
}		
