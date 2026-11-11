#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,a[500010],s[500010];
bool cmp(int a,int b){
    return a>b;
}
bool check(int l,int r){
    ll tar=a[l];
    ll sum=s[r]-s[l-1];
    int len=r-l+1;
    if(tar*len-sum<=m){
        return true;
    }
    else return false;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];

    }
    int ans=0;
    for(int i=1;i<=n;i++){

        int l=i,r=n;
        if(check(i,r)){
            ans=max(ans,r-i+1);
            break;
        }
        int mid;
        while(l<r){
            mid=(l+r)>>1;


            if(check(i,mid)){
                if(mid==n)break;
                if(!check(i,mid+1))break;
                l=mid;
            }else{
                r=mid;
            }
        }
        ans=max(ans,mid-i+1);

    }
    cout<<ans;
    return 0;
}