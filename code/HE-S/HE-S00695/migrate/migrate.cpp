#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[100005],y[100005],cnm=0,cnt=0;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cnm=0;
		cnt=0;
		cin>>n>>d;
		for(int j=0;j<n;j++)
		{
			cin>>x[j];
			
		}
		cnt=x[n-1]-x[0]+1;
		if(cnt<d*2)
		{
			cout<<"0";
			return 0;
		 } 
		if(cnt%(d*2)==0)
		{
			cnm=cnt/(d*2);
		}
		else
		{
			cnm=cnt/(d*2)+1;
		}
		
		cout<<cnm<<endl;
	}
	return 0;
}
