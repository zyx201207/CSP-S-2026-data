#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt,d;
ll n,m;
ll a[100001],vis[100001];
ll finds(ll b){
    ll sum=0,c=b,max1=LONG_MAX,t=0;
    for(ll i=0;i<n;i++){
        if(a[i]<=b&&vis[i]==0){
            sum=abs(a[i]-b);
            if(sum<max1){
                max1=sum;
                c=a[i];
                t=i;
            }
        }
    }
    cnt+=abs(c-b);
    vis[t]=1;
    if(cnt>m){
        cnt=0;
        return d;
    }else{
        d++;
        finds(b);
    }
}
ll suan(int x){
    int sum=0,t=0;
    for(int i=0;i<n;i++){
        if(a[i]<=x){
            sum+=abs(x-a[i]);
            t++;
        }
    }
    if(sum<=m){
        return t;
    }else{
        return -1;
    }
}
void clears(){
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0,q;
    vis[1]=1;
    for(ll i=0;i<n;i++){
        if(suan(a[i])==-1){
            vis[i]=1;
            q=finds(a[i]);
        }else{
            q=suan(a[i]);

        }
        if(q>ans){
            ans=q;
        }
        clears();
    }
    cout<<ans;
    return 0;
}
