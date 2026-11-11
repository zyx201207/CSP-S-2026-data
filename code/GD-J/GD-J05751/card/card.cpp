#include<bits/stdc++.h>
using namespace std;
int n,k,a[600001],b[600001]={0} ;
int main() 
{
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	cin>>n>>k ;
	for(int i=1;i<=n;i++) cin>>a[i] ;
	for(int j=1;j<=n;j++)
	{
		int f[600001]={0},l[600001]={0},p[600001]={0} ;
		int cnt=j-1 ;
		for(int i=j;i<=n;i++)
		{
			cnt++ ;
			f[cnt]=a[i] ;
			if(!l[a[i]]) l[a[i]]=i ;
			else if(l[a[i]])
				if(cnt>l[a[i]]) cnt=l[a[i]] ;
		}
		for(int i=1;i<=cnt;i++) 
		{
			if(!p[f[i]])b[f[i]]++ ;
			p[f[i]]++ ;
		}
	}
	for(int i=1;i<=k;i++) cout<<b[i]<<' ' ;
}


