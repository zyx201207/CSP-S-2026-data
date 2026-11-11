#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m,ii,jj;
	long long s=0;
 cin>>n>>m;
 for(int i=0;i<n;i++)cin>>a[i];
 	for(int u=1;u<m;u++)
 	{
	 s=-1;
 	for(int i=0;i<n;i++)
 	{
 		for(int j=i+1;j<n;j++)
 		{
 			if(a[i]&a[j]>s)
			 {
			 s=a[i]&a[j];
			 ii=i;
			 jj=j;
		}
		}
	 }
	 a[ii]=s;
	 a[jj]=0;
}
 
 cout<<s;
    
    return 0;
}

