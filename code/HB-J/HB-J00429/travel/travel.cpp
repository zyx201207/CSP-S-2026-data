#include<bits/stdc++.h>
using namespace std;
long long a,a1;
string b,b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>a1>>b1;
    if(a1==a)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==b1[0]&&b[1]==b1[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(b[2]>='D'&&b1[2]>='D'||b[2]<'D'&&b1[2]<'D')cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(int(b[2])+1==int(b1[2])||int(b[2])==int(b1[2]+1))cout<<1;
    else cout<<0;
    return 0;
}
