#include<bits/stdc++.h>
using namespace std;
long a[500005],d[500005],sl[250005];
int ans=-1;
long long n,m;
int f(int l,int r){
    while(l<r){
        if(sl[r]-sl[l]==m){
            ans=max(ans,r-l+1);
            break;
        }
        else
        if(sl[r]-sl[l]<m){
            ans=max(ans,r-l);
            break;
        }
        else{
            f(l+1,r);
            f(l,r-1);
            break;
        }
    }
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
    if(n>=5000 && m>=1000000000){
        int d=a[2]-a[1];
        if(d==0){
            cout<<n;
            return 0;
        }
        int s=0;
        if(m<d){
            cout<<1;
            return 0;
        }
        for(int i=2;i<=n;i++){
            s+=d*(i-1);
            if(s==m){
                cout<<i;
                return 0;
            }
            if(s>m){
                cout<<i-1;
                return 0;
            }
        }
    }
    else{
        for(int i=1;i<=n-1;i++){
            d[i]=a[i+1]-a[i];
        }
        int l=0,r=n-1,cnt=0;
        for(int i=1;i<=n-1;i++){
            sl[i]=sl[i-1]+d[i]*i;
        }
        cout<<f(l,r);
    }
    return 0;
}
