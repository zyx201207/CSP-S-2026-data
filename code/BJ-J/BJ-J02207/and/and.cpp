#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int n,m;
int ty[N];
int ans = 0;
int check(){
    int an = a[ty[1]];
    for(int i = 2;i<=m;i++){
        an=an&a[ty[i]];
    }
    return an;
}
void dfs(int step){
    if(step == m+1){
        ans = max(ans,check());
    }
    for(int i = 1;i<n;i++){
        if(!find(ty+1,ty+step,i)){
            ty[step] = i;
            dfs(step+1);
            ty[step] = 0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        ans=max(ans,a[i]);
    }
    if(m>1){
        ans = 0;
        dfs(1);
    }
    cout << ans;
    return 0;
}
