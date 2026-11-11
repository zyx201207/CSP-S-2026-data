#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char an,bn;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>an>>b1>>b2>>bn;
    if(a1!=b1)cout<<"0000";
    else{
        if(b2!=a2)cout<<"1000";
        else{
            int n=an,m=bn;
           if(n<m)swap(n,m);
           if(n=='B')cout<<"1111";
           else if(n=='C'){
               if(m=='B')cout<<"1111";
               else cout<<"1110";
           }
           else if(n=='D')cout<<"1100";
           else if(n=='F'){
               if(m=='D')cout<<"1111";
               else cout<<"1110";
           }
        }
    }
    return 0;
}