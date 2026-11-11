#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==s1){
    cout<<1;
    }else{
    cout<<0;
    return 0;
    }
    if(c1=="A"&&c2=="B"||c1=="B"&&c2=="C"||c1=="D"&&c2=="F"){
    cout<<1;
    }else{
    cout<<0;
    return 0;
    }
    return 0;
   }
