#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500100],ans[500100],h,k;
vector<int>now;
int t[500100];
int lowbit(int u){return u&(-u);}
void change(int u,int k){
    while(u<=n){
        t[u]+=k;
        u+=lowbit(u);
    }
    return;
}
__int128 query(int u){
    __int128 ls=0;
    while(u){
        ls+=t[u];
        u-=lowbit(u);
    }
    return ls;
}
int erfen(int x){
    int l=k,r=x,ls=1;
    while(l<=r){
        int mid=(l+r)/2;
        __int128 lyc=h*(x-mid+1);
        lyc-=query(n-mid+1);
        lyc+=(x-mid+1)*(a[x+1]-a[x]);
        if(lyc<=m){
            r=mid-1;
            ls=mid;
        }else{
            l=ls=mid+1;
        }
    }
    return ls;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int cnt=0;
    int fst=1;
    k=1;
    for(int i=1;i<=n;i++){
        if(i!=n&&a[i]==a[i+1]){
            cnt++;
            continue;
        }
        cnt++;
        k=erfen(fst-1);
        ans[i]=fst-k+cnt;
        while(cnt){
            cnt--;
            change(n-i+cnt+1,a[i]);
        }
        h=a[i];
        fst=i+1;
    }
    int res=1;
    for(int i=1;i<=n;i++){
        res=max(res,ans[i]);
    }
    cout<<res<<endl;
    return 0;
}
