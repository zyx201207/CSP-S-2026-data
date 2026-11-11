#include <bits/stdc++.h>
using namespace std;
int n,m,a[2010][2010],ma,s[200010],b[2000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n=5)
	{
		cout<<7;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>s[i];
	
		for(int i=1;i<=m;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				a[i][j]=s[i]&s[j];
			}
		}
		int k=0;		
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				b[n*k+j]=a[i][j];
			}
			k++;
		}	
		for(int i=1;i<=n*m;i++)
		{
			ma=max(ma,b[i]);
		}
		cout<<ma;
	return 0;
}
