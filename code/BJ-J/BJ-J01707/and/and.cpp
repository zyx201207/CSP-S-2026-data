#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10;
int n,m;
int a[N];
int b[N];
//1->i take m
int dfs(int r,int c){
    if (c>r) return 0;
    if (c==0) return 1073741823;
    if (r==0) return 0;
    if (r==c) return b[r];
    return max(dfs(r-1,c),(int)(dfs(r-1,c-1)&a[r]));
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i],b[i]=a[i];
    for (int i=2;i<=n;i++) b[i]&=b[i-1];
    // for (int i=1;i<=n;i++) cout << b[i] << " ";
    cout << dfs(n,m);
    return 0;
}