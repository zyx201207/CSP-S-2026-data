#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000009];
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    c=read(),t=read();
    while(t--){
        ll n,d,ans=0;
        n=read(),d=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        ll res=(d*2-1)/(a[2]-a[1]);
        cout<<(n-res)<<"\n";
    }
    return 0;
}
