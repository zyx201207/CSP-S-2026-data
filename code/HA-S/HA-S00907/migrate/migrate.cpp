#include<bits/stdc++.h>
using namespace std;
int c,t,n,x[2000001],daan[2000001],d;
int main(){
	freopen("migrate.in","read",stdin);
	freopen("migrate.out","w",stdout);
	int sum=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		if(n<2*d)
		{
			daan[i]==0;
		}
		else
		{
			daan[i]=n-(d+1);
		}
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
	
	}
	for(int i=1;i<=t;i++)
	{
		cout<<daan[i]<<endl;
	}
	return 0;
}
