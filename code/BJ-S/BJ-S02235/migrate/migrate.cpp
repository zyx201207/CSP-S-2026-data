#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5005;
ll t, n, d, a[N], ans;
int b[N], f[N], cnt[N];

bool check(int u, int v){
    memset(f, 0x3f, sizeof f);
    memset(cnt, 0, sizeof cnt);
    cnt[u]=1; f[u]=0;
    for(int i=u;i<=v;i++)
        for(int j=i+1;j<=b[i];j++)
            if(f[i]+1<f[j]){
                f[j]=f[i]+1;
                cnt[j]=cnt[i];
            }else if(f[i]+1==f[j]){
                cnt[j]+=cnt[i];
            }
    return cnt[v]==2;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin>>t>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=0;
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(a[i]+d>=a[j])
                    b[i]=j;
                else break;
        ans=0;
        for(int i=1;i<=n;i++)
            for(int j=b[i]+1;j<=n;j++){
                if(check(i, j))
                    ans++;
            }
        cout<<ans<<endl;
    }
    return 0;
}