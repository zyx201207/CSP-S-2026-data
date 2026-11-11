#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1,s1,c2,s2,ans;
	cin>>c1>>s1>>c2>>s2; 
    if(c1==c2)ans+='1';
    else {cout<<"0000";return 0;}
    if(s1[1]==s2[1]&&s1[0]==s2[0]) ans+='1';
    else {cout<<"1000";return 0;}
    if(s1[2]>='D'&&s2[2]>='D'){cout<<ans+"11";return 0;}
    else if(s1[2]<='C'&&s2[2]<='C')ans+='1';
    else {cout<<ans+"00";return 0;}
    if(abs(s1[2]-s2[2])==1) ans+='1';
	else ans+='0';
	cout<<ans;
    
    return 0;
}
