#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);

	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	bool x,y;
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			if(a[i]==b[i]) x=1;
			else x=0; 
		}
	}
	if(x==1) cout<<1;
	if(x==0) 
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(a1[i]==b1[i]) y=1;
			else y=0; 
		}
	}
	if(y==1) {
		cout<<1;
	if((a1[2]>='A'&&a1[2]<='C'&&b1[2]>='A'&&b1[2]<='C')||a1[2]>='D'&&a1[2]<='F'&&b1[2]>='D'&&b1[2]<='F') cout<<1;	
	
	else 
	{
		cout<<"00";
		return 0;
	}
	
	if(a1[2]==b1[2]+1) cout<<1;
	else if(a1[2]==b1[2]-1) cout<<1;
	else cout<<0;
	}
	
	if(y==0)
	{
		cout<<"000";
		return 0;
	} 
	
	
	
	
	
	return 0;
}
