#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long x=0;
    int f=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-48;
        c=getchar();
    }
    return x*f;
}
long long n,m,a[500005],ans,sum[500005];
bool check(int l,int r){
    return a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid,i))r=mid;
            else l=mid+1;
        }
        ans=max(ans,(long long)i-l+1);
    }
    cout<<ans;
    return 0;
}
