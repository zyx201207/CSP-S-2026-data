#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long ss1,ss2;
    string c1,s1,c2,s2;
    cin>>c1>>ss1>>s1>>c2>>ss2>>s2;
    if(c1==c2)cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    if(ss1==ss2) cout<<1;
    else cout<<0;
    if((s1=="A"||s1=="B"||s1=="C")&&(s2=="A"||s2=="B"||s2=="C")){
        cout<<1;
    }
    else if((s1=="D"||s1=="F")&&(s2=="D"||s2=="F")) cout<<1;
    else cout<<0;
    if((s1=="A"&&s2=="B")||(s1=="B"&&s2=="C")||(s1=="D"&&s2=="F")) cout<<1;
    else cout<<0;
    return 0;
}