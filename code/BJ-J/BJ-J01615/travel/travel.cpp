#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool q=1;
    int a=(c1[0]-'0')*10+c1[1]-'0';
    int b=(c2[0]-'0')*10+c2[1]-'0';
    if (a==b){
        cout<<'1';
    }else{
        cout<<'0';
        q=0;
    }
    a=(s1[0]-'0')*10+s1[1]-'0';
    b=(s2[0]-'0')*10+s2[1]-'0';
    if (a==b && q){
        cout<<'1';
    }else{
        cout<<'0';
        q=0;
    }
    if ((s1[2]-'A')<=2 && (s2[2]-'A')<=2 && q){
        cout<<'1';
    }else if((s1[2]-'A')>2 && (s2[2]-'A')>2 && q){
        cout<<'1';
    }else{
        cout<<'0';
        q=0;
    }
    if (((s1[2]-'A')-(s2[2]-'A')==1 || (s2[2]-'A')-(s1[2]-'A')==1) && q){
        cout<<'1';
    }else{
        cout<<'0';
    }
    return 0;
}