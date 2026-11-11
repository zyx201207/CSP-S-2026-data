#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<0;
    }
    int m=max(s1.s2);
    int n=min(s1,s2);
    int s=m-n;
    if(s<5){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;

}
