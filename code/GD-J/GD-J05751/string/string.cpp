#include<bits/stdc++.h>
using namespace std;
long long ans=0 ;
struct z
{
	int k ;
	char p ;
}a[700001] ;
int main()
{
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	int n ;
	cin>>n ;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k>>a[i].p ;
 	}	
	for(int i=1;i<=n;i++)
	{
		if(a[i].k==a[n-i+1].k&&i<n/2&&a[i].p==a[n-i+1].p) continue ;
		else if(a[i].k==a[n-i+1].k&&i<n/2) 
		{
			ans+=a[i].k ;
			continue ;
		}
 		else for(int j=1;j<=a[i].k;j++) s+=a[i].p ;
	}
	for(int i=0;i<int(s.size()/2);i++)
	{
		if(s[i]!=s[s.size()-i-1]) ans+=1 ;
	}
	cout<<ans ;
}


