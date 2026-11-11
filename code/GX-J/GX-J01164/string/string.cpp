#include<bits/stdc++.h>
using namespace std;
int n=0,a[1000],len,f[100000];
char c[1000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        len+=a[i];
    }
    int mx;
    for(int i=1;i<=n;i++){
        mx=max(mx,a[i]);
    }
    int mi;
    for(int i=1;i<=n;i++){
        mi+=a[i];
    }
    mi-=mx;
    int ans=min(mx,mi);
    cout<<ans<<"\n";
    return 0;
}
