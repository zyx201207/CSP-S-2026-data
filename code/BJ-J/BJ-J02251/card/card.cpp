#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+5, M=3e5+5;
int n, m, a[N], lst[M], ans[M];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        lst[a[i]]=i;
    }
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            ans[a[i]]++;
            i=lst[a[i]];
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}