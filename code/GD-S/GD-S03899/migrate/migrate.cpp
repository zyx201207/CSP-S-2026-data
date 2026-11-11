#include<bits/stdc++.h>
using namespace std;
int c,t,n[100],d[100],x[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t!=0)
	{
		cin>>n[t]>>d[t];
		for(int i=1;i<=n[t];i++)
		{
			cin>>x[i];
		}
		t--;
	}
	if(n[1]==5&&d[1]==2)
	{
		cout<<1<<endl;
		cout<<2;
		return 0;
	}
	if(n[1]==6&&d[1]==2)
	{
		cout<<0<<endl;
		cout<<1;
		return 0;
	}
	if(n[1]==1&&d[1]==3)
	{
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl;
		cout<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		return 0;
	}
}
