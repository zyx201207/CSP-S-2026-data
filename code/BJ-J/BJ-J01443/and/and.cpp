#include<bits/stdc++.h>
using namespace std;
int a[2005], n, m;
long long ans;
const long long po=pow(2, 30)-1;
void dfs(int level, long long cnt, int x){
    if(level==m){
        ans=max(ans, cnt);
        return;
    }
    else if(x==n+1){
        return;
    }
    dfs(level+1, cnt&a[x], x+1);
    dfs(level, cnt, x+1);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int ma=0, all=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    all=a[1];
    for(int i=1;i<=n;i++){
        ma=max(ma, a[i]);
        all=all&a[i];
    }
    if(m==n){
        cout<<all;
        return 0;
    }
    if(m==1){
        cout<<ma;
        return 0;
    }
    if(m==2){
        int an=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                an=max(an, a[i]&a[j]);
            }
        }
        cout<<an;
        return 0;
    }
    dfs(0, po, 1);
    cout<<ans;
    return 0;
}
