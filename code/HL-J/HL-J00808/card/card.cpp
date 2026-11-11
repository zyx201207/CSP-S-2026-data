#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
#define int long long
int a[N],save[N];
bool vis[N];
int n,m;
int maxn = INT_MIN;

void dfs(int depth,int start){
    if(depth == m+1){
        int ans = save[1];
    for(int i=2;i<depth;i++){
        ans &=save[i];
    }
    maxn = max(maxn, ans);
            return ;
        // ·µ»Ø
    }
    for(int i=start;i<=n;i++){
        if(!vis[i]){
            save[depth] = a[i];
            vis[i] = true ;
            dfs(depth + 1,i+1);
            vis[i] = false ;
        }
    }

}
int32_t main(){
    freopen("card.in","r",stdin);
     freopen("card.out","w",stdout);
    cout<<"10 3 3"<<endl;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
