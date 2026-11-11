#include<bits/stdc++.h>
using namespace std;
int s,n;
string x,y,a,b;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdin);
	cin>>a>>x>>b>>y;
	if(a==b)cout<<11; 
	else {
		cout<<0000;
		return 0;
	}
	if(x[1]==y[1]&&x[2]==y[2])cout<<11;
	else cout<<0;
	if(x[3]=='A'||x[3]=='B'||x[3]=='C')
	{
		if(y[3]=='A'||y[3]=='B'||y[3]=='C')
		{
			cout<<1;
		}
		else
		{
			if(y[3]=='E'||y[3]=='D')
			{
				cout<<1;
			}
			else cout<<0;
		} 
	}
	
	return 0;
}

