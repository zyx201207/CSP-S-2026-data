#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int a,b;
    string a1,b1;

    cin>>a>>a1>>b>>b1;

    int a2=stoi(a1.substr(0,2)),b2=stoi(b1.substr(0,2));
    char a3=a1[2],b3=b1[2];

    if(a!=b)
        cout<<"0000";
    else if(a2!=b2)
        cout<<"1000";
    else if(!!((a3=='A'||a3=='B'||a3=='C')^(b3=='A'||b3=='B'||b3=='C')))
        cout<<"1100";
    else if(abs(a3-b3)!=1)
        cout<<"1110";
    else
        cout<<"1111";
    
    cout<<'\n';
    
    return 0;
}