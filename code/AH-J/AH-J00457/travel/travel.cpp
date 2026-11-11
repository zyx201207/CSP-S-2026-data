#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;//c1[1]==c2[1] and c1[2]==c2[2]
    else 
    {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1])cout<<1;
	 else 
    {
		cout<<"000";
		return 0;
	}
	if(((s1[2]=='A' or s1[2]=='C' or s1[2]=='B') and (s2[2]=='A' or s2[2]=='C' or s2[2]=='B')) and (s1[2]-'A'+s2[2]-'A'!=7))cout<<1;
	else 
	{
		cout<<"00";
		return 0;
	}
	if(s1[2]-s2[2]==1 or s2[2]-s1[2]==1) 
	{
		if(s1[2]+s2[2]-'A'-'A'!=5)cout<<1;
	    else cout<<0;
    }
    else cout<<0;

    return 0;
}
