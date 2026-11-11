#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = a;i <= b;i++)
using namespace std;
int n,m,mmax = -1;
int a[200005],dp[200005];
bool b[200005];
void dfs(int d){
    if(d == m+1){
    //cout << m << endl;
        int s = dp[1];
        //int k = mmax;
        rep(i,2,m){
            s &= dp[i];
        }
        mmax = max(s,mmax);
        //if(k != mmax){
        //    rep(i,1,m){
        //        cout << dp[i] << ' ';
        //    }
        //    cout << mmax;
        //   cout << endl;
        //}
        return ;
    }

    rep(i,1,n){
        //cout << 1 << endl;
        if(b[i]){
            dp[d] = a[i];
            b[i] = false;
            dfs(d+1);
            b[i] = true;
        }

    }
    return ;
}
int main(){
    //<<speed of light>> - Never gonna give you up,never gonna let you down
    //Arknights JT8-3 XX XXXX!(?
    //0~10 pass 13 pass?
    //rp++
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rep(i,1,n){
        cin >> a[i];
    }
    if(n <= 2000){
        memset(b,true,sizeof(b));
        //cout << m << endl;
        dfs(1);
        cout << mmax;
    }else{
        sort(a+1,a+1+n,greater<int>());
        int s = a[1];
        rep(i,2,m){
            s &= a[i];
        }
        cout << s;
    }

    return 0;
}
