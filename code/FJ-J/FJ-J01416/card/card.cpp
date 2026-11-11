#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005]={0},z[300005]={0};
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n,m,x=0;
	cin>>n>>m;
	x=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=x;i++)
	{
		bool f=false;
		for(int j=1;j<=n-x;j++)
		{
			if(s[j]==a[i])
			{
				for(int y=j+1;y<=n-j;y++)
				{
					a[++x]=s[y];
					s[y]=0;
				}
				f=true;
			}
		}
		if(f==false)
		{
			s[n-x+1]=a[i];
		}
		z[n-x+1]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<z[i]<<" ";
	}
	return 0;
}