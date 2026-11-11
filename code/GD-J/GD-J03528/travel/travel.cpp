#include <bits\stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string cc,ss,cccc,sss;
    cin>>cc>>ss>>cccc>>sss;
    if(cc!=cccc){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(ss[0]!=sss[0]||ss[1]!=sss[1]){
        cout<<"000";
        return 0;
    }
    cout<<'1';
    bool ssa=0,sssa=0;
    if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'){
        ssa=1;
    }
    if(sss[2]=='A'||sss[2]=='B'||sss[2]=='C'){
        sssa=1;
    }
    if(ssa!=sssa){
        cout<<"00";
        return 0;
    }
    cout<<'1';
    if(ss[2]-sss[2]!=1&&ss[2]-sss[2]!=-1){
        cout<<'0';
        return 0;
    }
    cout<<'1';
    return 0;
}

