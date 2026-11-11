#include<bits/stdc++.h>
using namespace std;
#define int long long 
void read(int &x){
    char c=getchar();
    bool fl=0;
    x=0;
    while(c<'0'||c>'9'){
        if(c=='-')fl=1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    if(fl)x=-x;
}
int n,m;
const int N=5e5+5;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n);
    read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    sort(a+1,a+1+n);
    int l=1,r=0;
    int sum=0;
    int ans=0;
    while(r<=n){
        sum+=a[++r];
        while(a[r]*(r-l+1)-sum>m&&l<=r)sum-=a[l++];
        ans=max(ans,r-l+1);
    }
    printf("%lld",ans);
    return 0;
}