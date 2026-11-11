#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    char c1,s1,c2,s2;
    string ans="1100";
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) ans="0000";
    else if(c1==c2&&s1!=s2&&s1-s2!=1&&s2-s1!=1&&s1-s2!=2&&s2-s1!=2&&(s2-s1==3||s1-s2==3||s1-s2==4||s2-s1==4))ans="1000";
    else if(c1==c2&&s1!=s2&&s1-s2!=1&&s2-s1!=1&&s1-s2!=2&&s2-s1!=2)ans="1100";
    else if(c1==c2&&s1!=s2&&s1-s2==2&&s2-s1==2)ans="1110"; 
	else if(c1==c2&&s1-s2==1&&s2-s1==1)ans="1111";
    cout<<ans;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

