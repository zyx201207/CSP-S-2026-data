#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],q=0;
bool v[200010];
void f(int d,long long s)
{
    if(d==m)
    {
        if(s>q)
        {
            q = s;
        }
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!v[i])
        {
            v[i] = 1;
            long long x = s&a[i];
            f(d+1,x);
            v[i] = 0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        v[i] = 1;
        f(1,a[i]);
        v[i] = 0;
    }
    cout << q;
    return 0;
}
