#include <bits/stdc++.h>
using namespace std;
long long a[200000],maxx,n,m;
void dfs(long long w,long long dx,long long maxxx){
    if(w>n+1||dx>m) return ;
    maxx=max(maxx,maxxx);
    dfs(w+1,dx,maxxx);
    dfs(w+1,dx+1,maxxx&a[w+1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    dfs(1,0,0);
    cout << maxx;
    return 0;
}
