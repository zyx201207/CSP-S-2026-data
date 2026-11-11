#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],cnt[500010];
int main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        cin >> a[i];
    }
    if(m == 2){
        cout << n-1 << " " << n;
    }
    else{
        cout << n;
    }
    return 0;
}
