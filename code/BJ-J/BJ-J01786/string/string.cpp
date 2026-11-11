#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;
const int N=2e5+11;
int c[N];
char b[1000000009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;cin>>n;
    rep(i,1,n){
        int v=cnt;
        char s;
        cin>>c[i]>>s;
        rep(j,v+1,c[i]+v){
            b[++cnt]=s;
        }
    }
    int r=cnt,ans=0;
    for(int l=1;l<=cnt/2;l++){
        //cout<<b[l]<<" "<<b[r]<<'\n';
        if(b[l]!=b[r])
            ans++;
        r--;
    }
    cout<<ans;
    return 0;
}