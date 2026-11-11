#include<bits/stdc++.h>
#define int long long
#define il inline
#define co const
#define re register
using namespace std;
il int read();
co int N=5e5+10;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    co int n=read(),m=read();
    for(re int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+1+n);
    int maxx=0;
    for(re int i=1;i<=n;++i){
        int l=1,r=i;
        while(l<r){
            co int mid=(l+r)>>1;
            if(a[i]*(i-mid)-(a[i-1]-a[mid-1])<=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        a[i]+=a[i-1];
        maxx=max(maxx,i-l+1);
    }
    cout<<maxx;
    return 0;
}
il int read(){
    int ans=0;
    bool op=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')op=1;
        ch=getchar();
    }
    while(isdigit(ch)){
        ans=(ans<<1)+(ans<<3)+(ch^48);
        ch=getchar();
    }
    if(op)return -ans;
    return ans;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
 */