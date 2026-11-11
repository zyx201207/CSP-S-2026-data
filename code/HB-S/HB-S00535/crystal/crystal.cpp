/*
in:
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
out:
3

4
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxN=5e3+5;

int n;

ll m,ans=LONG_MIN;

ll a[maxN],diff[maxN][maxN];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<=5000){
        memset(diff,-1,sizeof diff);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                diff[i][j]=a[j]-a[i];
            }
        }
        for(ll i=1;i<=n;i++){
            diff[i][i]=0;
        }
        ll cnt,now;
        for(int j=1;j<=n;j++){
            cnt=0,now=0;
            for(int i=1;i<=n;i++){
                if(diff[i][j]==-1)
                    break;
                cnt+=diff[i][j];
                if(cnt>m)
                    break;
                now++;
            }
            ans=max(now,ans);
        }
        cout<<ans;
    }else{
        ll d=a[2]-a[1];
        ll cnt=0,ans=1;
        for(int i=d;i<=a[n]/d;i+=d){
            cnt+=i;
            if(cnt>m)
                break;
            ans++;
            cnt+=i;
            if(cnt>m)
                break;
            ans++;
        }
        cout<<ans;
    }
    return 0;
}
