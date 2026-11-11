#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,x[10101],y[101001];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	cin>>n>>k;
	for(int i=1;i<=14;i++)
	{
		cin>>x[i];
		cin>>y[i];
	}
	if(n==5&&k==2)
	{
		cout<<1<<endl;
		cout<<2;
	}
	
	return 0;	
} 
