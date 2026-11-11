#include <bits/stdc++.h>

using namespace std;
string c1,c2,s1,s2;
bool f=1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string s1x=s1.substr(2,1),s2x=s2.substr(2,1);
    if(c1==c2){
        cout<<1;
    }
    if(c1!=c2){
        cout<<0;
        f=0;
    }
    bool flag=0;
    if(s1.substr(0,2)==s2.substr(0,2) && f==1){
        cout<<1;
    }
    if(!flag){
        cout<<0;
        f=0;
    }
    flag=0;
    if((s1.substr(0,2)==s2.substr(0,2)) && ((s1x>="A" && s1x<="C" &&s2x>="A" && s2x<="C") || (s1x>="D" && s1x<="F" &&s2x>="D" && s2x<="F")) && f==1){
        cout<<1;
        flag=1;
    }
    if(!flag){
        cout<<0;
        f=0;
    }
    flag=0;
    char a=s1x[0],b=s2x[0];
    if(max(a,b)-min(a,b)==1 && f==1){
        cout<<1;
        flag=1;
    }
    if(!flag) cout<<0;
    return 0;
}
