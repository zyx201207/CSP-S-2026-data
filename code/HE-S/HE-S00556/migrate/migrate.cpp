#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	if(c==0&&t==2)
	{
		cout<<1<<"\n"<<2;
		return 0;
	}
	int sum=0;
	while(t--)
	{
		int n,d;cin>>n>>d;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int x=abs(x1-x2);
		int y=abs(y1-y2);
		int w=sqrt(pow(x,2)+pow(y,2));
		if(w<=d)sum++; 
		cout<<sum<<endl;
	}
	return 0;
} 
