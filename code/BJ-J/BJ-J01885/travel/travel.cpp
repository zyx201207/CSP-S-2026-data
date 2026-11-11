#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else if(c1!=c2){
        cout<<"0000"<<'\n';
        return 0;
    }
    bool ok=true;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]) ok=false;
    }
    if(ok){
        cout<<"1";
        if((s1[2]=='C'||s2[2]=='C')&&(s1[2]=='D'||s2[2]=='D')) cout<<"00";
        else if(s1[2]-'A'+1==s2[2]-'A'||s1[2]-'A'-1==s2[2]-'A') cout<<"11";
        else cout<<"10";
    }
    else cout<<"000";
    cout<<'\n';
    return 0;
}
