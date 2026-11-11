#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1 == s3 && s2[0] == s4[0] && s2[1] == s4[1]){
        cout<<"1100";
    }
    else if(s1 == s3 && s2[0] == s4[0] && s2[1] != s4[1]){
        cout<<"1000";
    }else{
        cout<<"0000";
    }

    return 0;
}
