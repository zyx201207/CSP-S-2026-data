#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,len,ans;
char c;
string s;
bool check(string st){
    string sstt=st;
    reverse(sstt.begin(),sstt.end());
    return st==sstt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a>>c;
        for(ll j=1;j<=a;j++){
            s+=c;
        }
    }
    if(check(s)){
        cout<<0;
        return 0;
    }
    len=s.size();
    for(ll i=0;i<=len/2-1;i++){
        if(s[i]!=s[len-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
