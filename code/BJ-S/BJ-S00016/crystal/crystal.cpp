#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1000;
int a[maxn],c[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool is=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            is=0;
        }
    }
    if(is){
        for(int i=1;i<=n;i++){
            if(i*(i+1)/2>m){
                cout<<i;
                return 0;
            }
        }
    }
    is=1;
    int cha =a[2]-a[1];
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]!=cha){
            is=0;
        }
    }
    if(is){
        for(int i=1;i<=n;i++){
            if(cha*(i*(i+1)/2)>m){
                cout<<i;
                return 0;
            }
        }
    }

    for(int i=1;i<n;i++){
        c[i]=a[i+1]-a[i];
    }
    long long ans=-1e8*1000,idx=0;
    long long w=m;
    for(long long i=2;i<=n;i++){
        w=m;
        idx=0;
        for(long long j=i;j>=1;j--){
            long long cha=a[i]-a[j];
            if(w-cha>=0){
                idx++;
                w-=cha;
            }else{
                break;
            }
        }
        ans=max(ans,idx);
    }
    cout<<ans;
}
