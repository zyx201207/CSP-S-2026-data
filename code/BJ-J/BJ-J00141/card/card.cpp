#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+11;
int a[N];
int ans[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    int x = a[n];

    sort(a+1,a+n+1);

    int id = 1;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[id]) a[++id] = a[i];
        ans[id]++;
    }
    ans[x] = n;

    for(int i=1;i<=m;i++) cout << ans[i] <<" ";
    return 0;
}
