#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string c1,s1,c2,s2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0,j=0;i<c1.size(),j<c2.size();i++,j++){
        if(c1[i]!=c2[j]){
            cout<<"0000";
            return 0;
        }
    }
    cout<<1;
    for(int i=0,j=0;i<s1.size()-1,j<s2.size()-1;i++,j++){
        if(s1[i]!=s2[j]){
            cout<<"000";
            return 0;
        }
    }
    cout<<1;
    char a=s1[s1.size()-1];
    char b=s2[s2.size()-1];
    if(a>='A'&&a<='C'&&(b=='D'||b=='F')||b>='A'&&b<='C'&&(a=='D'||a=='F')){
            cout<<"00";
            return 0;
    }
    cout<<1;
    if((abs(a-b)==1||b=='F'&&a=='D'||b=='D'&&a=='F')) cout<<1;
    else cout<<0;
    return 0;
}
