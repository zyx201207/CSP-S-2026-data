#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    ll x1,x2;
    string t1,t2;
    cin>>x1>>t1>>x2>>t2;
    if(x1 != x2){
        cout<<"0000"<<'\n';
        return 0;
    }
    cout<<1;
    if(t1[0] != t2[0] || t1[1] != t2[1]){
        cout<<"000"<<'\n';
        return 0;
    }
    cout<<1;
    char c1 = t1[2],c2 = t2[2];
    ll flag1 = 0,flag2 = 0;
    if(c1 == 'A' || c1 == 'B' || c1 == 'C')flag1 = 1;
    if(c2 == 'A' || c2 == 'B' || c2 == 'C')flag2 = 1;
    if(flag1 != flag2){
        cout<<"00"<<'\n';
        return 0;
    }
    cout<<1;
    if(c2 < c1)swap(c1,c2);
    if(c1 == 'A' && c2 == 'B' || c1 == 'B' && c2 == 'C' || c1 == 'D' && c2 == 'F')cout<<1<<'\n';
    else cout<<0<<'\n';
    return 0;
}