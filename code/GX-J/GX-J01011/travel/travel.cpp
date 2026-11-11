#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    string s1,s2;
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1!=c2){
        cout<<"0000";
    }
    else if(s1[2]=='C'&&s2[2]=='D' || s1[2]=='D'&&s2[2]=='C'){
        cout<<"1100";
    }
    else if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'){
        cout<<"1111";
    }
    else if(s2[2]=='A'&&s1[2]=='B'||s2[2]=='B'&&s1[2]=='C'){
        cout<<"1111";
    }
    else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
        cout<<"1111";
    }
    else{
        cout<<"1110";
    }
}
