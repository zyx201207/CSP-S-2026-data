#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int pd[1000];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    pd['A']=1;
    pd['B']=2;
    pd['C']=3;
    pd['D']=11;
    pd['F']=12;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    bool b=1;
    for(int i=0;i<=1;i++)
    {
        if(s1[i]!=s2[i])
        {
            b=0;
        }
    }
    if(b){
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(pd[s1[2]]+pd[s2[2]]<10||pd[s1[2]]+pd[s2[2]]>20){
        cout<<1;
    }
    else {
        cout<<"00";
        return 0;
    }
    if(abs(pd[s1[2]]-pd[s2[2]])==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
