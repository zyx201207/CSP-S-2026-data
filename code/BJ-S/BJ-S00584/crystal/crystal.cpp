#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long q(int x){
    long long cnt=0;
    for(int i=1;i<=x-1;i++){
        cnt+=a[x]-a[i];
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    unsigned long long n,m;
    cin>>n>>m;
    bool qx1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            qx1=0;
        }
    }
    if(qx1==1){
        for(int i=1;i<=n;i++){
            if(i*(i-1)/2>m){
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        long long cnt1=q(mid);
        if(cnt1==m){
            for(int i=mid+1;i<=n;i++){
                if(a[i]>a[mid]){
                    cout<<i-1;
                    return 0;
                }
            }
            cout<<n;
            return 0;
        }else if(cnt1<m){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    for(int i=mid+1;i<=n;i++){
        if(a[i]>a[mid]){
            cout<<i-1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
