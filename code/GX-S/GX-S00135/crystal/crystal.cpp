#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;

ll read(){
    ll x=0,f=1;
    char c;
    c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return f*x;
}

long long a[N],d[N];
long long n,m,sum,de,q[N],s=1,t,ans;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++){
        while(s<=t&&sum+(t-s+2)*d[i]>m){sum-=de;de-=q[s++];}
        if(sum+d[i]<=m){sum+=(t-s+2)*d[i];q[++t]=d[i];de+=d[i];}
        ans=max(ans,t-s+2);
    }
    cout<<ans;
    return 0;
}


