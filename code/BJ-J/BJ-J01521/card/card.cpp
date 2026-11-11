#include <iostream>
#include <cstdio>

using namespace std;

int a[500005];
int p[300005];
int ans[300005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[a[i]] = i;
    }
    for(int i=1;i<=n;i++){
        int j = i;
        while(j != n + 1){
            while(p[a[j]] == j && j <= n){
                ans[a[j]]++;
                j++;
            }
            if(j > n){
                break;
            }
            j = p[a[j]];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
