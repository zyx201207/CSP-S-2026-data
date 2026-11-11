//GZ-J00079 贵阳市新世界学校 李冠儒
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void zf(){
    ll n;
    cin>>n;
    string s;
    ll L=0;
    for(int i=0;i<n;i++){
        ll a;char c;
        cin>>a>>c;
        L+=a;
        while(a--)s.push_back(c);
    }
    s=" "+s;
    ll cnt=0;
    for(int i=1;i<=L/2;i++){
        if(s[i]!=s[L+1-i])cnt++;
    }
    cout<<cnt<<'\n';
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    int t=1;
    //cin>>t;
    while(t--)zf();
    return 0;
}
