#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c,n,m,q,a[N],cnt;
vector<pair<int,int> >t[N];
//map<int,int>t;
void dfs(int x,int s,int t){
    if(x >= n) return;
    if(x == t){
        cnt++;
        return;
    }
    for(int i = 1;i <= m;i++){
        dfs(x + i,s,t);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&q);
    while(q--){
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
            //t[a[i]]++;
        }
        /*memset(dp,0x3f,sizeof(dp));
        dp[0] = 0;
        for(int i = -1e4;i <= 1e4;i++){
            t[i] = max(t[i],t[a[i]-m] + 1);
        }
*/
        int ans = 0;
        for(int i = 1;i < n;i++){
            for(int j = i+1;j <= n;j++){
                cnt = 0;
                dfs(1,i,j);
                if(cnt == 2) ans++;
            }
        }
        /*int mx = -1e9;
        for(int i = 1;i <= n;i++) mx = max(mx,t[i]);
        printf("%d\n",mx);*/
        printf("%d\n",ans);
    }
    return 0;
}
