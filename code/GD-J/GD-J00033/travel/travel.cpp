#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2; 
string ans;
map<char,int> mp;
bool check(){
	return (!(s1[2]=='A'&&s2[2]=='C'))&&(!(s1[2]=='C'&&s2[2]=='A'));
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    mp['A']=1,mp['B']=1,mp['C']=1,mp['D']=2,mp['E']=2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)ans+='1';
    else ans+='0';
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])ans+='1';
    else ans+='0';
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&mp[s1[2]]==mp[s2[2]])ans+='1';
    else ans+='0';
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&mp[s1[2]]==mp[s2[2]]&&check())ans+='1';
	else ans+='0'; 
    cout<<ans<<endl;
	return 0;
}
//水题 
//好了样例全过了，好怕重蹈CSP-J 2025
//17 06A 17 06C
//1110
//xju love ltc 
