#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
bool b_1,b_2;
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2) cout<<'1';
	else 
	{cout<<"0000";
	 return 0;
	}
	if((s_2[0]==s_1[0])&&(s_1[1]==s_2[1])) cout<<'1';
	else 
	{cout<<"000";
	 return 0;
	}
	if(s_1[2]<='C') b_1=1;
	if(s_2[2]<='C') b_2=1;
	if(b_1==b_2) cout<<'1';
	else 
	{cout<<"00";
	 return 0;
	}
	if(b_1==b_2)
	{
	  if(s_1[2]>='D') cout<<'1';
	  else if((s_1[2]=='A'&&s_2[2]=='B')||(s_2[2]=='A'&&s_1[2]=='B')||(s_1[2]=='B'&&s_2[2]=='C')||(s_1[2]=='C'&&s_2[2]=='B'))
	  cout<<'1';
	  else cout<<'0';
	}

	return 0;
}
