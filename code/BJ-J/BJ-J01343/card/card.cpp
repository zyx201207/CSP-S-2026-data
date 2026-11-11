#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N],c[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        c[a[i]] = i;
    }
    for(int i=1;i<=m;i++)
        cout << c[i] << ' ';
    return 0;
}
