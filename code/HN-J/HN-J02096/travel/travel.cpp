#include<bits/stdc++.h>
using namespace std;
string s,s1,c1,c; 
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("travel.in" , "r", stdin);
	//freopen("travel.out" , "w" ,stdout);
	cin>>s>>c>>s1>>c1;
	if(s==s1) 
	{
		cout<<1;
		if(c[0]==c1[0]&&c[1]==c1[1]) 
		{
			cout<<1;
			if(c[2]>='A'&&c[2]<='C'&&c1[2]>='A'&&c1[2]<='C'||c[2]>='D'&&c[2]<='F'&&c1[2]>='D'&&c1[2]<='F') 
			{
				cout<<1;
				if(c[2]-1==c1[2]||c[2]+1==c1[2]) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
