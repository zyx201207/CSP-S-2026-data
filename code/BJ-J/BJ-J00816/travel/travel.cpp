#include<bits/stdc++.h>
using namespace std;
int a,b,la,lb;
string sa,sb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>sa>>b>>sb;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(!((sa[0]==sb[0])&&(sa[1]==sb[1]))){
        cout<<"000";
        return 0;
    }
    cout<<1;
    la=sa[2]-'A';
    lb=sb[2]-'A';
    if(!(((la<=2)&&(lb<=2))||((la>2)&&(lb>2)))){
       cout<<"00";
       return 0;
    }
    cout<<1;
    if((la-lb==1)||(lb-la==1))cout<<1;
    else cout<<0;
    return 0;
}
