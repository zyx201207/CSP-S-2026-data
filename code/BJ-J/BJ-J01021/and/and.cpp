#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int popcnt(int p){
    int cnt=0;
    while(p){
        cnt+=(p&1);
        p>>=1;
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=20){
        long long ans=0;
        for(int mask=1;mask<(1<<n);mask++){
            if(popcnt(mask)!=m)continue;
            bitset<30> bs=mask;
            //cout<<bs<<endl;
            long long cnt=(1ll<<31)-1;
            //cout<<cnt<<endl;
            for(int i=0;i<n;i++){
                if(bs[i]){
                    cnt&=a[i+1];
                    //cout<<cnt<<endl;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }else if(m==1){
        long long ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,(long long)a[i]);
        cout<<ans<<endl;
    }else if(m==n){
        long long ans=(1ll<<31)-1;
        for(int i=1;i<=n;i++)ans&=a[i];
        cout<<ans<<endl;
    }else if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

