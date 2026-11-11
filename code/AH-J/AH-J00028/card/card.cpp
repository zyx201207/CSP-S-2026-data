#include <bits/stdc++.h>
using namespace std;
int p;
bool y(&vector<int> g,int k,int n){
    for(int i = 1;i <= n;++i){
        if(g[i] == k){
            p = i;
            return true;
        }
    }
    return false;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;++i){
        scanf("%d",&a[i]);
    }
    int ans = 0;
    vector<int> g(n + 1);
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            g[j] = -1;
        }
        for(int j = i;j <= n;++j){
            if(y(g,a[i],n)){
                for(int w = p;w <= n;++w){
                    g[w] = -1;
                }
            }
            else{
                g[j] = a[i];
            }
        }
        if(y(g,a[i],n)){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
