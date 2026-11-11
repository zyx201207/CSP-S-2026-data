#include<bits/stdc++.h>
using namespace std;
int a[200005],ma,s,n,m;
int an(int js,int l)
{
	for(int i=l;l<=n;i++)
	{	
		if(js==-1)
		{
			s=a[i-1];
			return s;
		}else
		{	
			js--;
			an(js,i+1);
		}
		s=(s&a[i]);
	if(ma<s)
			ma=s;
			
	}
}
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	an(m,0);
	cout<<ma;
	return 0;
}
