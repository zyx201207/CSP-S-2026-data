#include<bits/stdc++.h>
using namespace std;

const long long NN=1e18+2;

long long max(long long x,long long y){
    if(x>y)return x;
    else return y;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n;
    long long m;
    cin>>n>>m;
    long long a[n];

    long long maa=-NN;
    long long mii=NN;

    for(int i=0;i<n;i++){
        cin>>a[i];
        maa=max(maa,a[i]);
        mii=min(mii,a[i]);
    }

    long long ans=0;

    for(long long j=mii;j<=maa;j++){
        long long k=m;
        long long co[n];
        for(int i=0;i<n;i++)co[i]=NN;
        for(int i=0;i<n;i++){
            if(a[i]>j){
                continue;
            }
            co[i]=j-a[i];
        }


        sort(co,co+n);

        long long ans2=0;
        for(int i=0;i<n;i++){
            if(k>=co[i]){
                ans2++;
                k-=co[i];
            }
        }
        ans=max(ans,ans2);
    }

    cout<<ans;
    return 0;
}
