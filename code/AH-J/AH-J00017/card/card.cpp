#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 5e5+5;
int n,m;
int a[M],s[M],app[M];
int ans[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    //int t0=clock();

    cin >> n >> m;
    for(int i=1 ; i<=n ; ++i)
    {
        cin >> a[i];
        ans[a[i]]=i;
    }
    for(int i=1 ; i<=m ; i++) cout << ans[i] << ' ';

    //cout << "\ntimeuse:" << clock()-t0 << "ms";
    cout << endl;
    return 0;
}
