#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr long long maxn=5e5+10,inf=0x7fffffffffffffff;
long long n;
long long m;
long long a[maxn];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (long long i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+1+n);
    long long num=0,ans=1;
    long long siz=1,it=1;
    for (long long i=2;i<=n;i++)
    {
        siz++;
        num+=(a[i]-a[i-1])*(siz-1);
        // cerr << "---------------" << endl;
        // cerr << i << endl;
        // cerr << num << endl;
        // cerr << "---------------" << endl;
        while (num>m)
            num-=a[i]-a[it++],siz--;
        ans=max(ans,siz);
    }
    cout << ans << endl;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
