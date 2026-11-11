#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int n,m,a[N],b[N],sum[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++){
        if(sum[i]!=sum[i-1]&&i!=2) break;
        else if(i==n) {
            ans=1;
            while(m>=0&&m>=sum[2]){
                m-=sum[2];
                ans++;
                sum[2]+=sum[3];
            }
            cout<<ans;
            return 0;
        }
    }
    if(n%2==0) cout<<n/2;
    else cout<<n/2+1;
    return 0;
}
