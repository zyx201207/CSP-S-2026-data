#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
namespace Manaka_Ao{
    #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
    char buf[1<<20],*p1=buf,*p2=buf;
    inline ll read(){
        ll ans=0,w=1;
        char ch=getchar();
        while(ch<48||ch>57){
            if(ch=='-')w=-1;
            ch=getchar();
        }
        while(ch>=48&&ch<=57){
            ans=(ans<<1)+(ans<<3)+ch-48;
            ch=getchar();
        }
        return w*ans;
    }
    const int N=500005;
    int n;
    ll m;
    ll a[N];
    int main(){
        n=read(),m=read();
        for(int i=1;i<=n;i++)a[i]=read();
        sort(a+1,a+1+n);
        ll sum=0;
        int ans=1;
        for(int i=1,top=1;i<=n;i++){
            sum+=a[i];
            while(a[i]*(i-top+1)-sum>m){
                sum-=a[top];
                ++top;
            }
            ans=max(ans,i-top+1);
        }
        cout<<ans<<'\n';
        return 0;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    Manaka_Ao::main();
    return 0;
}
/*
g++ -std=c++14 crystal.cpp -o crystal -lm -O2 -static -Wl,-stack=2000000000
.\crystal

*/