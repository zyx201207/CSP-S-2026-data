#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0;
    cin>>n;
    ll tmp;
    char tmp1;
    string s;
    for(int i=0;i<n;i++){
        cin>>tmp>>tmp1;
        for(ll j=0;j<tmp;j++){
            s.push_back(tmp1);
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            ans++;
            s[s.size()-i-1]=s[i];
        }
    }
    cout<<ans;
    return 0;
}
