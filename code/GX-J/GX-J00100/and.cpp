#include <bits/stdc++.h>
using namespace std;

int add(int a,int b)
{
    int temp = 1,cnt = 0;
    while(a>0&&b>0)
    {
        if(a%10==1&&b%10==1)
        {
            cnt+=temp;
        }
        a/=10;
        b/=10;
        temp*=10;
    }
    return cnt;
}
int prime(int a)
{
    int cnt = 0;
    int temp = 1;
    while(a>0)
    {

        cnt+=(a%2)*temp;
        temp*=10;
        a/=2;
    }
    return cnt;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],b[200005];
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];

    }
    if(m == n)
    {
        int aa = a[1]&a[2];
        for(int i = 3;i<=n;i++)
        {
            aa = aa&a[i];
        }
        cout<<aa;
        return 0;
    }
    if(m == 1)
    {
        int aa = a[1];
        for(int i = 2;i<=n;i++)
        {
            aa = max(aa,a[i]);
        }
        cout<<aa;
        return 0;
    }

    int cnt = 0;
    int aa = a[1]&a[2];
        for(int i = 3;i<=m;i++)
        {

            int bb = max(aa,a[i]);
            aa = aa&bb;
        }
        cout<<aa;
    return 0;
}
