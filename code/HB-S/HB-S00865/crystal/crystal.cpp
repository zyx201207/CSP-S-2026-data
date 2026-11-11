#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,a[500005],maxx=-1,minn=0x3f3f3f3f3f,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxx=max(a[i],maxx);
        minn=min(a[i],minn);
    }
    sort(a,a+n);
    for(int i=minn;i<maxx;i++){
        ll x=m,sum=0;
        for(int j=0;j<n&&x>0;j++){
            if(a[j]<i){
                x-=a[j]-i;
                if(x>=0)
                    sum++;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
