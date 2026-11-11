#include<bits/stdc++.h>
using namespace std;
int x,y;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>x>>a>>y>>b;
	if(x!=y)cout<<"0000";
	else 
	{
		cout<<'1';
		if(a[0]!=b[0]||a[1]!=b[1])cout<<"000";
		else
		{
			cout<<'1';
			if(a[2]=='A')
			{
				if(b[2]=='B')cout<<"11";
				else if(b[2]=='C')cout<<"10";
				else cout<<"00";
			}
			else if(a[2]=='B')
			{
				if(b[2]=='A')cout<<"11";
				else if(b[2]=='C')cout<<"11";
				else cout<<"00";
			}
			else if(a[2]=='C')
			{
				if(b[2]=='B')cout<<"11";
				else if(b[2]=='A')cout<<"10";
				else cout<<"00";
			}
			else if(a[2]=='D')
			{
				if(b[2]=='F')cout<<"11";
				else cout<<"00";
			}
			else if(a[2]=='F')
			{
				if(b[2]=='D')cout<<"11";
				else cout<<"00";
			}
		}
	}
	return 0;
} 
