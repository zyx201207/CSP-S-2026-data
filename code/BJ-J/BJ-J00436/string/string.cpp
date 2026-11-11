#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],L=0;
char c[200010];
int pre[200010];
int ans=0;

void jump(int &rid,int &go,int need,char C){
    if(go+need<=a[rid]){
        if(c[rid]!=C) ans+=need;
        go+=need;
        return ;
    }
    while(need){
        if(go+need<=a[rid]){
            if(c[rid]!=C) ans+=need;
            go+=need;
            break;
        }
        need-=(a[rid]-go);
        if(c[rid]!=C) ans+=(a[rid]-go);
        rid++,go=1;
        need--;
        if(c[rid]!=C) ans++;
    }
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        pre[i]=pre[i-1]+a[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(L&1){
        int mid=(L+1)/2;
        int ix,SM=0;
        for(int i=1;i<=n;i++){
            if(SM+a[i]>=mid){
                ix=i;
                break;
            }
            SM+=a[i];
        }
        int tmp=mid-SM-1;
        int rid=ix,go=mid-SM;
        jump(rid,go,tmp,c[ix]);
        for(int i=ix-1;i>=1;i--){
            //jump for a[i]
            jump(rid,go,a[i],c[i]);
        }
        cout<<ans;
    }
    else{
        int mid=L/2;
        int ix,SM=0;
        for(int i=1;i<=n;i++){
            if(SM+a[i]>=mid){
                ix=i;
                break;
            }
            SM+=a[i];
        }
        int tmp=mid-SM-1;
        int rid,go;
        if(mid-SM==a[ix]){
            rid=ix+1;
            go=1;
            if(c[rid]!=c[ix]) ans++;
        }
        else{
            rid=ix;
            go=mid-SM+1;
        }

        jump(rid,go,tmp,c[ix]);
        for(int i=ix-1;i>=1;i--){
            jump(rid,go,a[i],c[i]);
        }
        cout<<ans;
    }
    return 0;
}
