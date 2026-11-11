#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],s1,s2;
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i];
}
if(m>2)
{
for(int i=1;i<=n;i++)
{
	if(a[i]!=a[i+1])
	{
		cout<<i<<" ";
	}
}
}
else
{
for(int i=1;i<=n;i++)
{
for(int j=1;j<=i;j++)
{
	if(a[j]==a[i]) 
	{
		for(int k=j;k<i;k++)
		{
			a[k]=0;
		}
	}
}	
for(int i=n;i>=1;i--)
{
if(a[i]==1) {s1++;break;}	
} 
for(int i=n;i>=1;i--)
{
if(a[i]==2) {s2++;break;}	
} 
}
cout<<s1<<" "<<s2-1;
}
	return 0;
} 
