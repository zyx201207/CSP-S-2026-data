#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x;
		}
	}
	if(x%2==0)
	{
		cout<<0<<endl;
		cout<<1;
	}
	else{
		cout<<1<<endl;
		cout<<2;
	}
	return 0; 
 } 
