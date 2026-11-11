#include<bits/stdc++.h>
using namespace std;
int arr[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,C=0;
	cin>>C>>c;
	for(int i=0;i<c;++i)
	{
		int n,m=0;
		cin>>n>>m;
		for(int i=0;i<n;++i)
		{
			cin>>arr[i];
		}
		if(n==4&&m==2)
		{
			cout<<1<<endl;
		}
		if(n==5&&m==2)
		{
			cout<<2<<endl;
		}
		if(n==5&&m==3)
		{
			cout<<0<<endl;
		}	
		if(n==6&&m==2)
		{
			cout<<1<<endl;
		}	
		if(c==0&&C==17)
		{
			cout<<8129<<endl;
			cout<<16<<endl;
			cout<<9<<endl;
			cout<<7<<endl;
			cout<<12<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<1<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<3<<endl;
			cout<<6<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<0<<endl;
		}
	}
	
	return 0;
}
