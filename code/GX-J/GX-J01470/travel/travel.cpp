#include<bits/stdc++.h>
using namespace std;
int a1,a2,g1,g2,l1,l2;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else{
    cout<<"0000";
    return 0;
    }
    for(auto i:s1){
    if(i>='A'&&i<='F')
        break;
        a1+=i;
    }
    for(auto i:s2){
    if(i>='A'&&i<='F')
        break;
        a2+=i;
    }
    if(a1==a2)
        cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    for(auto i:s1){
    if(i>='A'&&i<='C')
        g1+=1;
    }
    for(auto i:s2){
    if(i>='A'&&i<='C')
        g2+=1;
    }
    if(g1==g2){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    for(auto i:s1){
    if(i>='A'&&i<='C')
        l1+=i;
    }
    for(auto i:s2){
    if(i>='A'&&i<='C')
        l2+=i;
    }
    if(l2==l1||l2-l1==1||l1-l2==1)
        cout<<"1";
    else cout<<"0";
return 0;
}
