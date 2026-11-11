#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans=1e18;
long long n,m,t,l,r,mid,tmpi;
void dfs(long long tmpidx,long long nowt,long long nowans,long long starti)
{
    if(nowt<=0){
        if(ans!=1e18) ans=max(ans,nowans);
        else ans=nowans;
        return ;
    }
    if(nowans>=ans||tmpidx==0||tmpidx==n+1) return ;
    nowans++;
    if(tmpidx!=1) dfs(tmpidx-1,nowt-abs(a[tmpidx]-a[starti]),nowans,starti);//left
    if(tmpidx!=n) dfs(tmpidx+1,nowt-abs(a[tmpidx+1]-a[starti]),nowans,starti);//right
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long zhong=1,tzhong=1;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i]!=a[i-1]&&i!=1){
            zhong=max(zhong,tzhong);
            tzhong=1;
        }
        else tzhong++;
    }
    if(m==0){
        cout << zhong << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        dfs(i,m,0,i);
    }
    cout << ans << endl;
    return 0;
}
