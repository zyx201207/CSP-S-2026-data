#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[1000001],c;
    long long n,le,cnt=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>le;
        cin>>c;
        for(int j=1;j<=le;j++){
            a[++cnt]=c;
        }
    }
    for(int i=1;i<=cnt;i++){
        if(a[i]!=a[cnt-i+1]) ans++;
    }
    cout<<ans/2<<endl;
    return 0;
}
