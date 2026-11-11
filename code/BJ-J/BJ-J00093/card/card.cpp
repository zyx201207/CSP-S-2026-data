#include<bits/stdc++.h>
#define int long long
#define f first
#define se second
#define pii pair<int,int>
using namespace std;
int n,m,a[500010],last[300010],c[300010],x,y;
priority_queue<pii,vector<pii>,less<pii> > q1;
queue<pii> q2;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i],c[a[i]] = max(c[a[i]],i - 1);
    for(int i = 1;i <= m;i++) cout << c[i] << ' ';
    return 0;
}
