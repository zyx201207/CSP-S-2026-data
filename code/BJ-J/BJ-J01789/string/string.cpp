#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll x,n,k,cnt,a[N];
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    cin>>n;
    k=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        s[i]=c;
    }
    for(int i=1;(n+1)/2+i<=n;i++){
        if(s[i]!=s[(n+1)/2+i]) cnt+=min(a[i],a[n/2+1]);
    }
    cout<<cnt;
    return 0;
}

