#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],b[500010],c[500010];
long long cnt,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    memset(c,0x3f,sizeof(c));
    for(int i=1;i<=n;i++){
        c[i]=a[i]*i-b[i];
    }
    for(int i=1;i<=n+1;i++){
        if(c[i]>m){
            cout<<i-1;
            return 0;
        }
    }
    return 0;
}
