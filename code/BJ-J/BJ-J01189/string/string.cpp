#include<bits/stdc++.h>
#define ll long long
#define MAX 1000010
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s="";
    int a;
    char c;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    ll ans=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
           ans++;
        }
    }
    cout<<ans;
    return 0;
}
