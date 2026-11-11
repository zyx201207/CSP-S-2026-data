#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1])    cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])    cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67))    cout<<1;
    else if((s1[2]==68&&s2[2]==70)||(s1[2]==70&&s2[2]==68)){
        cout<<11;
        return 0;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(max(s1[2],s2[2])==min(s1[2],s2[2])+1)    cout<<1;
    else    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}