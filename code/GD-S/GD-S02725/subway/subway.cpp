#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int a[10005],b[10005],e[10005],qi[50],s[1005];
int main(){
	int flag=0;
	int flagi=0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int g=1;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=2*g-1;j++)
		{
			if(flag==0)
			{
				b[0]=1+2*g;
				flag=1;
			}
			cin>>b[i];
		}
		for(int h=1;h<=2*g-1;h++)
		{
			if(flagi==0)
			{
				e[0]=1+2*g;
				flagi=1;
			}
			cin>>e[i];
		}
	}
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<1;j++)
		{
			cin>>qi[j];
		}
		s[i]=b[i];
		s[i]=a[i];
		s[i]=e[i];
		s[i]=a[2*g];
	}
	for(int i=0;i<=q;i++)
	{
		cout<<s[i];
	}
	return 0;
}
