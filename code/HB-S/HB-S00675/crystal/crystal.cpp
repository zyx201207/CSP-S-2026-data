#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long ans=-1;
long long check(long long x,long long st){
    long long d=a[x],ann=0;
    for(int i=st;i<=x;i++){
        ann+=d-a[i];
    }
    if(ann<=m){
        ans=max(ans,x-st+1);
        return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    bool pd=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2&&a[i]-a[i-1]==a[i-1]-a[i-2]){
            pd=1;
        }
        else{
            pd=0;
        }
    }
    if(pd==1){
        long long k=a[n]-a[n-1];
        for(long long i=1;i<=n;i++){
            long long p=(i*(i-1))/2;
            if(p*k<=m){
                ans=i;
            }
        }
        if((m==0||n==1)&&ans==1){
            cout<<0;
            return 0;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    long long l=1,r=n,ll=1,fl=0;
    while(1){
        long long mid=(l+r)/2,w=mid;
        if(check(mid,ll)==1){
            l=mid+1;
        }
        else{
            if(fl==1){
                break;
            }
            ll++;
        }
        if(l>r){
            l=r;
            fl=1;
            ll--;
        }
        if(ll>mid||ll<1){
            break;
        }
    }
    if((m==0||n==1)&&ans==1){
        cout<<0;
        return 0;
    }
    cout<<ans;
    return 0;
}
