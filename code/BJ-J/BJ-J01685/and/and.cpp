#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[200005];
long long maxn = 0;
int maxi,maxj;
bool check[200005] = {false};

int dg(int m1,int i,int max_)
{
    if(m1 = 0)
    {
        return max_;
    }
    int maxdg = 0;
    check[i] = true;
    for(int j = 0;j < n;j++)
    {
        maxdg = max(maxdg,dg(m1 - 1,j,(max_ & a[j])));
    }
}

int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++)
    {
        int gg = dg(m,i,i);
        if(gg > maxn)
        {
            maxn = gg;
        }
    }
    cout << maxn;

    return 0;
}
