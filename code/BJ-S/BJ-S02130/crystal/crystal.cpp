#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
ll n,m;
ll l,r,mid;
bool pan(int k){
    for(long long i=1;i<=n-k+1;i++){
        ll w=k;
        ll sum=0;
        for(long long j=i+k-1;j>=i;j--){
            sum+=a[j]*w;
            w--;
        }
        if(sum<m||sum==m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(long long i=2;i<=n+1;i++){
        cin>>a[i];
    }
    sort(a+2,a+2+n);
    for(int i=1;i<n;i++){
        a[i]=a[i+2]-a[i+1];
    }
    l=0;
    r=n-1;
    n--;
    while(l!=r){

        if(pan(mid)==1) {
            l=mid;
            if((r+l)%2==1)  mid=(l+r)/2+1;
            else mid=(l+r)/2;
        }
        else {
            if((r+l)%2==1) r=mid-1;
            else r=mid;
            mid=(l+r)/2;
        }
    }
    cout<<l+1;
    return 0;
}
     /*                aaaaaaa
                    aaaaaaaaa
                aaaaaaaaaaaaaaaaaa
             aaaaaaaa       aaaaaaaaa
          aaaaaaaa              aaaaaaaaa
          aaaaaaaa              aaaaaaaaa
        aaaaaaaa                  aaaaaaaaa
        aaaaaaaa                  aaaaaaaaa
        aaaaaaaa                  aaaaaaaaa
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        aaaaaaaaa                  aaaaaaaa
        aaaaaaaa                   aaaaaaaa
        aaaaaaaaa                  aaaaaaaa





        kkkkkkk             kkkkkkk
        kkkkkkk            kkkkkkk
        kkkkkkk          kkkkkkk
        kkkkkkk        kkkkkkk
        kkkkkkk       kkkkkkk
        kkkkkkk     kkkkkkkk
        kkkkkkk  kkkkkkkk
        kkkkkkkkkkkkkkk
        kkkkkkk  kkkkkkkk
        kkkkkkk     kkkkkkkk
        kkkkkkk       kkkkkkkk
        kkkkkkk           kkkkkkkk
        kkkkkkk              kkkkkkk
        kkkkkkk               kkkkkkkk
        kkkkkkk                kkkkkkk
        */
