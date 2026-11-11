#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string rc,sc,rz,sz;
cin>>rc>>rz>>sc>>sz;
for(int i=1;i<=4;i++){
    if(rc==sc){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
return 0;
}
