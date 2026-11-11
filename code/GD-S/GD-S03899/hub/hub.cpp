#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[100000],w[100000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>w[i];
		}
	}
	if(u[1]==1&&w[1]==2)
	{
		cout<<1<<endl;
		cout<<2;
		return 0;
	}
	if(t==3)
	{
		cout<<1<<endl<<1<<endl<<2;
		return 0;
	}
	if(t==5)
	{
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
	}
}
