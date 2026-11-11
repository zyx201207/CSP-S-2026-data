#include <bits/stdc++.h>
using namespace std;

int main()
{   freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[200010];
    char b[200010];
    long long ans=0;
    long long cd=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        cd+=a[i];
    }
    cd=cd%2;
    int nn=(n+1)/2;
    for(int i=1;i<=nn;i++){
        if(b[i]!=b[n+1-i]){
            if(cd==0) ans+=a[i];
            else ans+=(a[n+1-i]+1);
        }
    }
    cout<<ans;
    return 0;
}
