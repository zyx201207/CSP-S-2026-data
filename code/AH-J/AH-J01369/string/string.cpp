#include<bits/stdc++.h>
using namespace std;
string s[10001],f,l;
int b[10001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>b[i]>>s[i];
        for(j=1;j<=b[i];j++){
            f=f+s[i];
        }
    }
    for(i=n;i>=1;i--){
        for(j=1;j<=b[i];j++){
            l=l+s[i];
        }
    }
    int ans=0;
    for(i=1;i<=n;i++){
        if(f[i]!=l[i]){
            ans++;
        }
    }
    cout<<ans/2;

    return 0;
}
