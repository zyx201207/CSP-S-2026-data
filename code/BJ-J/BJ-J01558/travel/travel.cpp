#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
string c1,s1,c2,s2,s="";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(s1[0]!=s2[0] || s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
        if(s2[2]=='D' || s2[2]=='F'){
            cout<<"1100";
            return 0;
        }
    }
    else{
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
            cout<<"1100";
            return 0;
        }//
        else{
            cout<<"1111";
            return 0;
        }
    }
    int k=abs(int(s2[2]-s1[2]));
    if(k==1)cout<<"1111";
    else cout<<"1110";
    return 0;
}
