#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<"0000";
    else if(!(s1[0]==s2[0] && s1[1]==s2[1]))cout<<"1000";
    else if(!((s1[2]-'A'<=2 && s2[2]-'A'<=2) || (s1[2]-'A'>2 && s2[2]-'A'>2)))cout<<"1100";
    else {
        if(s1[2]-'A'<=2 && s2[2]-'A'<=2){
            if(abs(s2[2]-s1[2])==1)
                cout<<"1111";
            else cout<<"1110";
        }
        else cout<<"1111";
    }
    return 0;
}