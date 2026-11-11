#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char a,char b){
    if(max(a,b)>='D'&&min(a,b)<='C'){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    if(check(s1[2],s2[2])){
        cout<<"1100";
        return 0;
    }
    if(max(s1[2],s2[2])-min(s1[2],s2[2])>1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
