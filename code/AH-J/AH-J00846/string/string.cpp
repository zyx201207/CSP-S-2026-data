#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m,cnt;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>m>>c;
        for(ll i=n;i<n+m;i++){
            s[i]=c;
        }
        n+=m;
    }
    if(n%2==0){
        for(ll i=0;i<n/2;i++) if(s[i]!=s[n-i-1]) cnt++;
    }
    else{
        for(ll i=0;i<(n-1)/2;i++){
            if(s[i]!=s[n-i-1]){
                    cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}

