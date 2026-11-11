#include<bits/stdc++.h>
using namespace std;
int n, m, r = 1;
int a[500005], k[300005], ans[300005];
int p[500005], last[300005];
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        k[a[i]]++;
    }
    for(int i = n; i >= 1; i--){
        if(last[a[i]] == 0){
            p[r] = a[i];
            last[a[i]] = r;
            r++;
            if(!vis[a[i]]){
				vis[a[i]] = 1;
                for(int j = 1; j < r; j++){
                    ans[p[j]] += k[a[i]];
                }
            } 
        }
        else{
            for(int j = last[a[i]] + 1; j < r; j++)last[p[j]] = 0;
            r = last[a[i]] + 1;
        } 
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
