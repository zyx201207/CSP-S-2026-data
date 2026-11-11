#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+1;
const int M = 1e5 + 1;
int c,n,m,d,q;
int w[N];
int a[501][N];
int r[M];
int solve(int qs,int zd){
    int ans = 1e18;//biguo
    if(a[qs][zd] != 0) ans = a[qs][qs] + a[qs][zd] + w[qs] + w[zd];
    if((c>=7  && c <= 11) || d <= 2){
        for(int i = 1;i<=n;i++){
            if(a[qs][i] != 0 && a[i][zd] != 0 && qs != i && zd != i){
                    ans = min(a[qs][i] + a[i][zd] + w[qs] + w[zd] + a[qs][qs], ans);
            }
        }
        return ans;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >>d >> q;
    for(int i = 1;i<=m;i++) cin >> w[i];
    for(int i = 1;i<=n;i++){
        int num;
        cin >> num;
        a[i][0] = num;
        for(int j = 1;j <= num;j++){
            int aj,t;
            cin >> aj >> t;
            a[i][aj] = t;
        }
    }
    for(int i = 1;i<=q;i++){
        int qs,zd;
        cin >> qs >> zd;
        if(qs == zd) cout << 0 << '\n';
        else{
            cout << solve(qs,zd) << '\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}