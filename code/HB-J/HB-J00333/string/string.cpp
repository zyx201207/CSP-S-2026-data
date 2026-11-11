#include<bits/stdc++.h>
using namespace std;
long long n,a,len,ans=0,a_=1;
char c;
char b[2147469999];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;cin>>c;
        for(int j=1;j<=a;j++){
            b[a_]=c;
            a_++;
        }
        len+=a;
    }
    for(int i=1;i<=(long long)len/2;i++){
        if(b[(len+1-i)]!=b[i]) ans++;
    }
    cout<<ans;
    return 0;
}
