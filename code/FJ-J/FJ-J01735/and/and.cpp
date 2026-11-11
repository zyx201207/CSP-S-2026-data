#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10010];
	cin>>n>>m;
	if(m==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		int ans=0;
		int x=0;
		while(a[i]>0)
		{
			x+=a[i]%2*pow(10,ans);
			ans++;
			a[i]/=2;
		}
		a[i]=x;
	}
	int pmax=-1,x,y;
	for(int i=0;i<n;i++)
	{
		int ans=0;
		for(int j=0;j<m;j++)
		{
			if(x%10==y%10) ans++;
			x/=10;
			y/=10; 
		}
		if(ans>pmax) pmax=ans;	
	}
	cout<<pmax;
	return 0;
}
