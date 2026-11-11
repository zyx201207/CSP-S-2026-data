#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],x=1,y=0,ans=0;
string s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
    while(x!=(n-y)){
        if(a[x]>a[n-y]){
            if(s[x]!=s[n-y]) ans+=(a[x]-a[n-y]);
            a[x]-=a[n-y];
            y++;
        }else if(a[x]<a[n-y]){
            if(s[x]!=s[n-y]) ans+=(a[n-y]-a[x]);
            a[n-y]-=a[x];
            x++;
        }else{
            if(s[x]!=s[n-y]) ans+=a[x];
            if(x+y==n-1) break;
            x++;
            y++;
        }
    }
    cout<<ans;
    return 0;
}

