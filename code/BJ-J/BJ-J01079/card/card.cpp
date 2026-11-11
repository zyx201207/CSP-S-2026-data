#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 9;
int a[MAXN],id[MAXN],tmp[MAXN];


int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m; cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    stack<int> v;
    for(int i = 1;i <= n;i++){
        memset(id,0,sizeof id);
        for(int j = i;j <= n;j++){
            if(id[a[j]] == 0){
                v.push(a[j]);
                id[a[j]]++;
            }
            else{
                while(v.top() != a[j]){
                    id[v.top()]--;
                    v.pop();
                }
                v.pop();
                v.push(a[j]);
            }
        }
        while(!v.empty()){
            tmp[v.top()]++;
            v.pop();
        }
    }
    for(int i = 1;i <= m;i++){
        cout << tmp[i] << " ";
    }
    return 0;
}
