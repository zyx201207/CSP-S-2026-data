#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define fin freopen("and.in","r",stdin);
#define fout freopen("and.out","w",stdout);
using namespace std;
const int digits=30;
int n,m,ans;
int a[200005];
int b[200005],nn;
void filt(int d)
{
    nn=0;
    for(int i=1;i<=n;i++)
        if(a[i]&(1 << d))
            b[++nn]=a[i];
    if(nn>=m)
    {
        ans|=(1 << d);
        n=nn;
        for(int i=1;i<=nn;i++)
            a[i]=b[i];
    }
}
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=digits;i>=0;i--)
        filt(i);
    cout << ans << endl;
    return 0;
}
