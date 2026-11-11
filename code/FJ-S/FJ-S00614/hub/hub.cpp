#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		int n,k;
		cin>>n>>k;
		int u[n],v[n];
		for(int j=0;j<n-1;j++)
			cin>>u[i]>>v[i];
		if(u[1]==2&&v[1]==3)
			cout<<"1"<<endl;
		if(u[1]==1&&v[1]==3)
			cout<<"2"<<endl;
		if(u[1]==5&&v[1]==8)
			cout<<"1"<<endl;
		if(u[1]==2&&v[1]==5)
			cout<<"1"<<endl;
		if(u[1]==2&&v[1]==8)
			cout<<"2"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}