#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int maxn=65536*65536*2048-1;
int a[205000];
int dfs(int p,int q,int weishu){
    if(q==m)return p;
    if(weishu>n&&q<m)return -10;
    int ans=-1;
    ans=max(ans,dfs(p,q,weishu+1));
    ans=max(ans,dfs(p&a[weishu],q+1,weishu+1));
    return ans;
}
unordered_map<int,bool>noi;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int res=0;
    int k=maxn;
    for(int i=1;i<=n;i++){
        cin>>a[i];res=max(res,a[i]);
        k=k&a[i];
    }
    if(n<=20){
        cout<<dfs(maxn,0,1);
        return 0;
    }
    if(m==1){
        cout<<res;
        return 0;
    }
    if(m==n){
        cout<<k;
        return 0;
    }
    if(m==2){
        sort(a+1,a+n+1);
        int ans=a[n]&a[n-1];
        int h=n-1;
        while(h>1){
            if(ans>a[h-1]){
                cout<<ans;
                return 0;
            }
            ans=max(ans,a[h]&a[h-1]);
            h--;
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){

    }
    int op=1;
    for(int i=1;i<=23;i++){
        noi[op]=1;
        op*=2;
    }
    bool pq=1;
    for(int i=1;i<=100;i++){
        if(!noi[a[i]]){
            pq=0;
        }
    }
    if(pq){
        cout<<res;return 0;
    }
    pq=1;
     for(int i=1;i<=100;i++){
        if(a[i]>4){
            pq=0;
        }
    }
    if(pq){
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==4){
                ans++;
            }
        }
        if(ans<=m){
            cout<<4;return 0;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==2||a[i]==3){
                ans++;
            }
        }
        if(ans<=m){
            cout<<2;return 0;
        }
         for(int i=1;i<=n;i++){
            if(a[i]==1||a[i]==3){
                ans++;
            }
        }
        if(ans<=m){
            cout<<1;return 0;
        }
        cout<<0;return 0;
    }

    return 0;
}
