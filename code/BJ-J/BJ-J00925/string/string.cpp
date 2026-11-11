#include <bits/stdc++.h>
using namespace std;

struct dst{char c;int l;long long d,de;} d[200005];
long long sum=0;
int n;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> d[i].l >> d[i].c;
    int l=1,r=n,now_l=d[1].l,now_r=d[n].l;
    while(l<r)
    {
        if(now_l<=now_r)
        {
            now_r-=now_l;
            if(d[l].c!=d[r].c) sum+=now_l;
            now_l=0;
        }
        else
        {
            now_l-=now_r;
            if(d[l].c!=d[r].c) sum+=now_r;
            now_r=0;
        }
        if(now_l==0) {l++;now_l=d[l].l;}
        if(now_r==0) {r--;now_r=d[r].l;}
        if(l==r) break;
    }
    cout << sum << endl;
    return 0;
}
