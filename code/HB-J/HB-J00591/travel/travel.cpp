#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')
       ||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')){
        cout<<"1";

    }
    else{
        cout<<"00";
        return 0;
    }
    int a=s1[2],b=s2[2];
    if('A'<=a&&a<='C'&&'A'<=b&&b<='C'&&abs(a-b)==1
    ||'D'<=a&&a<='F'&&'D'<=b&&b<='F'&&abs(a-b)==2){
        cout<<"1";
    }
    else{
        cout<<"0";
        return 0;
    }
    return 0;
}
