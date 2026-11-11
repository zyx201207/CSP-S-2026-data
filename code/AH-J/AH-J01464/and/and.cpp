#include<bits/stdc++.h>

using namespace std;
long long a[200005];
bool vis[200005];
int n,m;
long long ans;
void dfs(int k,long long s){
    //cout<<"dfs,"<<k<<","<<s<<"\nvis ";
    //for(int i = 0;i<n;i++) cout<<vis[i]<<' ';
    //cout<<"\nans "<<ans<<endl;
    if(k == m){
        ans = max(ans,s);
        return;
    }
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(k+1,s&a[i]);
            vis[i] = 0;
        }
    }
    return;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    long long mx = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    //6
    if(m == 1){
        for(int i = 0;i<n;i++){
            if(a[i]>mx) mx = a[i];
        }
        cout<<mx;
        return 0;
    }
    //7
    if(m == n){
        ans = a[0];
        for(int i = 1;i<n;i++) ans = ans&a[i];
        cout<<ans;
        return 0;
    }
    //1 2
    if(n<12){
        for(int i = 0;i<n;i++){
            vis[i] = 1;
            dfs(1,a[i]);
        }
        cout<<ans;
        return 0;
    }
    //8 9 10
    if(m == 2){
        ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j) continue;
                if(a[i]&a[j]>ans) ans = a[i]&a[j];
            }
        }
        cout<<ans;
        return 0;
    }
    //other
    for(int i = 0;i<n;i++){
        if(a[i]>mx) mx = a[i];
    }
    dfs(1,mx);
    cout<<ans;
    return 0;
}
/*

*/
//CCF please let me AC!
