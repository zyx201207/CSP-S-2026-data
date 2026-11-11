#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],pre[N],sum[N],h[N],m;
int n,ans,w;
bool flag;
/*
bool check(int x){
    ll w=0;
    for(int i=0;i<x;i++){
        w+=(a[x]-a[i]);
    }
    if(w>m) return 0;
    else return 1;
}
*/
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        pre[i]=a[i]-a[0];
        sum[i]=sum[i-1]+pre[i];
    }
    /*
    sort(pre+1,pre+n);
    for(int i=1;i<n;i++){
        h[i]=h[i-1]+pre[i];
    }
    for(int i=1;i<n;i++){
        if(sum[i]>m){
            cout<<i;
            flag=1;
            break;
        }
    }
    cout<<sum[n-1]<<" ";
    if(!flag) cout<<n;
    */
    for(int i=0;i<n;i++){
        int l=0,r=n-i-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid*pre[i+mid]-sum[i+mid-1]+sum[i]<=m){
                l=mid+1;
                ans=mid;
            }else{
                r=mid-1;
            }
        }
        w=max(w,ans+1);
    }
    cout<<w;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],m;
int n,ans;
bool check(int x){
    ll w=0;
    for(int i=0;i<x;i++){
        w+=a[x]-a[i];
    }
    if(w>m) return 0;
    else return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans+1;
    return 0;
}
*/
