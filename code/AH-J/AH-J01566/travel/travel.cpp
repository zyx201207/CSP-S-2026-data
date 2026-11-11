#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,c,b,d;
	cin>>a>>c>>b>>d;
	if(a==b)
		cout<<1;
	else 
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(c[1]==d[1])
		cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	int x=c.size(),y=d.size();
	if(c[1]<='9')
		x--;
	if(d[1]<='9')
		y--;
	if(c[x]=='A'){
		if(d[y]=='B')
			cout<<"11";
		else if(d[y]=='C')
			cout<<"10";
		else cout<<"00";
	}
	else if(c[x]=='B'){
		if(d[y]=='A' || d[y]=='C')
			cout<<"11";
		else cout<<"00";
	}
	else if(c[x]=='C'){
		if(d[y]=='B')
			cout<<"11";
		else if(d[y]=='A')
			cout<<"10";
		else cout<<"00";
	}
	else if(c[x]=='D'){
		if(d[y]=='F')
			cout<<"11";
		else cout<<"00";
	}
	else if(c[x]=='F'){
		if(d[y]=='D')
			cout<<"11";
		else cout<<"00";
	}
	return 0;
}
