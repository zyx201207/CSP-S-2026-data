#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		cout<<1;
		if((c[0]-'0')*10+c[1]-'0'==(d[0]-'0')*10+d[1]-'0')
		{
			cout<<1;
			if(((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((c[3]=='D'||c[3]=='F')&&(d[3]=='D'||d[3]=='F')))
			{
				cout<<1;
				if(c[2]=='B'||c[2]=='D'||c[2]=='F'||d[2]=='B'||d[2]=='D'||d[2]=='F')
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}	
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
	cout<<"0000";
	}
	return 0; 
}
