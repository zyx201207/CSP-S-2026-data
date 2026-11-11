#include<bits/stdc++.h>
const int N=2e6+3;
long long n,l,a[N];
using namespace std;
void work(){
    cin>>n>>l;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<n-1;i++)
        for(int j=i+2;j<=n;j++){
            if((__int128)a[j]-a[i]<=l) continue;
            int cnt=0;
            for(int k=i+1;k<j;k++)
                if((__int128)a[k]-a[i]<=l&&(__int128)a[j]-a[k]<=l)
                    cnt++;
            ans+=(cnt==2);
        }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int hyw,T;cin>>hyw>>T;
    while(T--) work();
    return 0;
}
