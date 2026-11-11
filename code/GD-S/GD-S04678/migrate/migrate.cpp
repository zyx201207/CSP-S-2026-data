#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		bool f=true;
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
		{
			cin>>x[i];
			if(i>=3) if(x[i]-x[i-1]!=x[i-1]-x[i-2]) f=false;
		} 
		int a=x[2]-x[1];
		cout<<a<<' ';
		int q=d/a;
		if(d<2*a) cout<<0;
		else cout<<(n-1)-(q+1)+1;
//		if(f)
//		{
//			int a=x[n]-x[n-1];
//			if(d<2*a) cout<<0;
//			else cout<<n-2*d+1;
//		}
//		else
//		{
//			if(c==0) cout<<1;
//			else cout<<9;	
//		}
		if(t>0) cout<<endl;
	}
	return 0;
}
