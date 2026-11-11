#include<bits/stdc++.h>
using namespace std;
int n,m,maxn = INT_MIN;
int a[500010],q[500010];
vector<int> p;
int main(){
    freopen("card1.in","r",stdin);
    freopen("card1.out","w",stdout);
    cin >> n >>m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    for(int i = 1;i <= m;i++){
        p.clear();
        for(int k = i;k <= n;k++){
            p[k]++;
            if(p[k] > 1){
                p.clear();
                p[k]--;
            }
        }
        for(int j = 1;j <= maxn;j++){
            if(p[j] == 1){
                q[j]++;
            }
        }
    }
    for(int j = 1;j <= maxn;j++){
        cout << p[j];
    }
    return 0;
}
