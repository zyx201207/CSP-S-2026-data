#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a;
        cin>>c;
        for(ll j=1;j<=a;j++){
            s+=c;
        }
    }
    ll cnt=0;
    ll sz=s.size();
    int flag=0;
    if(sz%2==0){
        flag==1;
    }


    for(ll i=0,j=sz-1;i<sz,j>=0;i++,j--){

        if(flag==1&&i==sz/2-1){
            break;
        }
        if(flag==0&&i==sz/2){
            break;
        }
        if(s[i]!=s[j]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

