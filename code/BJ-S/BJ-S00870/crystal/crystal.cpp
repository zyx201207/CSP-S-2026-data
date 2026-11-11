#include<bits/stdc++.h>
using namespace std;
#define int long long
// notice:long long
const int maxn=5e5+10;
int n,m;
int a[maxn];
int d[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        cin >> a[i] ;
    }
    sort(a+1,a+n+1);

    if(n<=5001){
        int ans=0;
        for(int s=1;s<=n;s++){
            memset(d,0,sizeof(d));
            int sum=0,cnt=0;
            for(int i=1;i<=n-s;i++){
                d[i]=(a[i+1]-a[i])*i;
                sum+=d[i];
                cnt++;
                if(sum>m){
                    break;
                }
            }
            ans=max(ans,cnt);
            for(int i=1;i<=n;i++){
                a[i]=a[i+1];
            }
        }
        cout << ans << '\n' ;
    }
    else {
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=i){
                flag=0;
                break;
            }
        }

        if(flag){
            int sum=0,ans=0;
            for(int i=1;i<=n;i++){
                sum+=i;
                ans++;
                if(sum>m)break;
            }
            cout << ans << '\n' ;
        }
        else {
            int sum=0,ans=0;
            int w=a[2]-a[1];
            for(int i=1;i<=n;i++){
                sum+=i*w;
                ans++;
                if(sum>m)break;
            }
            cout << ans << '\n' ;
        }
    }

    return 0;
}
