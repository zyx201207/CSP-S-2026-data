#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[2000005];
int nxt[2000005];
int last[2000005];
int vis[2000005];
int ans = 0;
void solve2(int l,int num){
    if(last[l] == l) return;
    int a = last[l],b = last[l + 1];
    ans += (b - a) * num;
    if(b == a) return;
    solve2(last[l],num);
}
void solve(int l,int num1,int num0){
    vis[l] = 1;
    //cout << l << " " << num1 << " " << num0 << endl;
    if(last[l] == l) return;
    int a = last[l + 1],b = last[l + 2];
    if(num1){
        ans += (b - a) * num1;
        if(b - a) solve2(last[l + 1],num1);
    }
    if(last[l] < last[l + 1] - 1){

        if(b - a) solve(last[l],num0 + 1,0);
        else solve(last[l],num1 + num0 + 1,0);
    }
    else if(last[l] == last[l + 1] - 1){
        if(last[l] == l - 1){
            if(b - a) solve(last[l],0,1 + num0);
            else solve(last[l],0,1 + num0 + num1);
        }
        else{
            if(b - a) solve(last[l],1,num0);
            else solve(last[l],1 + num1,num0);
        }
    }
    else{
        if(last[l] == l - 1){
            solve(last[l],0,1);
        }
        else{
            solve(last[l],1,0);
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        ans = 0;
        int n,d;
        scanf("%lld %lld",&n,&d);
        for(int i = 1;i <= n;i++){
            scanf("%lld",&s[i]);
        }
        int r = 1;
        for(int i = 1;i <= n;i++){
            while(s[r + 1] - s[i] <= d && r < n) r++;
            nxt[i] = r;
        }
        int l = n;
        for(int i = n;i >= 1;i--){
            while(s[i] - s[l - 1] <= d && l > 1) l--;
            last[i] = l;
        }
        for(int i = 1;i <= n;i++){
            vis[i] = 0;
        }
        for(int i = n;i >= 1;i--){
            if(vis[i]) continue;
            if(last[i] == i - 1) solve(last[i],0,1);
            else solve(last[i],1,0);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
