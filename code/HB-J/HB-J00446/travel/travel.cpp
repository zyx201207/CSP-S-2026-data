#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int ca(string s){
    return (s[2]=='A' || s[2]=='B' || s[2]=='C');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    // cout<<s1<<" "<<s3<<"\n";
    if (s1==s3) {
        cout<<"1";
        if (s2.substr(0,2)==s4.substr(0,2)) {
            cout<<"1";
            if (ca(s2)==ca(s4)) {
                cout<<"1";
                if ((((s2[2]+1)==s4[2] && s2[2]!='C') || ((s2[2]-1)==s4[2] && s2[2]!='D'))) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    cout<<endl;
    return 0;
}