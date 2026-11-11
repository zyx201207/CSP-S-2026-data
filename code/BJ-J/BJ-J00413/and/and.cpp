#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],ans1=-1e9;
//ll f[2010][2010];
void dfs(int i,int x,ll ans){
    //i in a,x in m,ans is answer
    if(x>m){
        ans1=max(ans,ans1);
        //cout << "ans:" << ans <<" " <<i <<" ";
        return;
    }
    //cout << ans <<" ";
    int now=ans;
    //not choose it
    for(int j=i+1;j<=n;++j){
        dfs(j,x,ans);
    }
    ans=now;
    //choose it
    if(x==0)  ans=a[i];
    ans&=a[i];

    for(int j=i+1;j<=n;++j){

        //cout << x+1 << " ";
        dfs(j,x+1,ans);
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    ll mina=2e9,maxa=-2e9,sumyu=0;
    for(int i=1;i<=n;++i){
        cin >> a[i];
        mina=min(mina,a[i]);
        maxa=max(maxa,a[i]);
        if(i==1)  sumyu=a[i];
        else sumyu&=a[i];
    }
    sort(a+1,a+n+1);
    if(m==1)  cout << maxa << "\n";
    else if(m==n)  cout << sumyu <<"\n";
    else if(m==2){
        ll ans=-2e9;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout << ans <<"\n";
    }
    else if(n<=20){
        dfs(1,0,0);
        cout << ans1 <<"\n";
    }
    //else if(m==n-1){
    //
    //}
    return 0;
}
