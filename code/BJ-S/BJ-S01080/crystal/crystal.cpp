#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m,a[500005],ch[500005],ans,tr[2000005],la[2000005];
void dp(int no,int len){
    if(la[no]!=0){
        la[2*no]+=la[no];
        tr[2*no]+=(len-len/2)*la[no];
        la[2*no+1]+=la[no];
        tr[2*no+1]+=(len/2)*la[no];
        la[no]=0;
    }
}
void add(int no,int l,int r,int l1,int r1,ll ad){
    if(l1<=l&&r<=r1){
        tr[no]+=(r-l+1)*ad;
        la[no]+=ad;
        return ;
    }
    int mid=(l+r)/2;
    dp(no,r-l+1);
    if(mid>=l1) add(2*no,l,mid,l1,r1,ad);
    if(mid<r1) add(2*no+1,mid+1,r,l1,r1,ad);
    tr[no]=tr[2*no]+tr[2*no+1];
}
ll query(int no,int l,int r,int l1,int r1){
    if(l1<=l&&r<=r1){
        return tr[no];
    }
    ll ans=0;
    int mid=(l+r)/2;
    dp(no,r-l+1);
    if(mid>=l1) ans+=query(2*no,l,mid,l1,r1);
    if(mid<r1) ans+=query(2*no+1,mid+1,r,l1,r1);
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        int ad=a[i]-a[i-1];
        add(1,1,n,1,i-1,ad);
        int l=1,r=i-1;
        while(l<=r){
            int mid=(l+r)/2;
            ll sum=query(1,1,n,mid,i-1);
            if(sum>m){
                l=mid+1;
            }
            else{
                r=mid-1;
                if(i-mid+1>ans) ans=i-mid+1;
            }
        }
    }
    cout<<ans;
}
