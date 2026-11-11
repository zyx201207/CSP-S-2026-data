#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
char s1s,s2s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    s1s=s1[2];
    s2s=s2[2];
    s1.pop_back();
    s2.pop_back();
    if(s1!=s2){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if((s1s=='D'&&s2s=='F')||(s2s=='D'&&s1s=='F')){
        cout<<11;
        return 0;
    }
    if((s1s=='A'&&s2s=='B')||(s2s=='A'&&s1s=='B')){
        cout<<11;
        return 0;
    }
    if((s1s=='B'&&s2s=='C')||(s2s=='B'&&s1s=='C')){
        cout<<11;
        return 0;
    }
    if((s1s=='A'&&s2s=='C')||(s2s=='A'&&s1s=='C')){
        cout<<10;
        return 0;
    }
    cout<<"00";
    return 0;
}
