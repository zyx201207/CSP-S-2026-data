#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int z=0,x=0;
	for(int i=0;i<a.size();++i)
	{
		if(a[i]==c[i])z++;
	}
	for(int i=0;i<2;i++)
	{
		if(b[i]==d[i])x++;
	}
	if(z==a.size())cout<<"1";
	else {
	cout<<"0000";
	return 0;
}
	
	
	if(x==2)cout<<"1";
	else 
	{
		cout<<"000";
		return 0;
	}
	
	
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'&&b[2]!=d[2])cout<<"1";
	else if(b[2]=='D'||b[2]=='F'&&d[2]=='D'||d[2]=='F'&&b[2]!=d[2])cout<<"1";
	else {
	  cout<<"00";
	  return 0;
}
	
	
	if(b[2]-1==d[2]||b[2]+1==d[2])
	{
		if(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C')
		cout<<"0";
		else cout<<"1";
	}
	else if(b[2]=='F'&&d[2]=='D'||b[2]=='D'&&d[2]=='F')cout<<"1";
	else cout<<"0";
	
	
	return 0;
}
