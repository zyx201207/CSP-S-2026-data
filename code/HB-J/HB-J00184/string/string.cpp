#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int N=2*1e5+5;

int n,a[N],s[N],l,r,ans;
char c[N];

int fid(int num){
    int l=1,r=n,m;
    while(l<r){
        m=(l+r)/2;
        if(s[m]-a[m]+1>num)
            r=m-1;
        else
            l=m+1;
    }
    return s[l]-a[l]+1<=num?l:l-1;
}

int sm(int w,int x,int y,int z){
    int aa;
    if(y<=w&&z<=x){
        aa=z-w;
    }
    if(y>=w&&z>=x){
        aa=y-x;
    }
    if(y<w&&z>x){
        aa=x-w;
    }
    if(y>w&&z<x){
        aa=z-y;
    }
    return abs(aa)+1;
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s[i]=s[i-1]+a[i];
    }

    for(int i=1;i<=n;i++){
        r=s[i]-a[i]+1;
        l=s[i];
        r=s[n]+1-r;
        l=max(s[n]+1-l,(s[n]+1)/2);
        int pos=fid(l);
        for(int j=pos;s[j-1]+1<=r;j++){
            if(c[j]!=c[i]){
                ans+=sm(l,r,s[j-1]+1,s[j]);
            }
        }
        if(s[i]>=s[n]/2)
            break;
    }
    cout<<ans;

    return 0;
}
