#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500010
#define M 300010
int n,m;
int a[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cout<<i+1<<" ";
    return 0;
}