#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a < b;
}

bool jo(int n)
{
    return n%2==0;
}

int num(int mid,int n,int m,int crystal[5*10^5])
{
    int cnt=0,same=0;
    for(int i=n-1;i>=0;i--)
    {
        m -= (mid-crystal[i]);
        if(m>=0)
        {
            cnt++;
        }
    }
    for(int i=n;i<2*n;i++)
    {
        if(crystal[i]==mid)
        {
            same++;
        }
    }
    return cnt+same;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m;
    cin >> n >> m;
    int crystal[n+1];
    for(int i=0;i<n;i++)
    {
        cin >> crystal[i];
    }
    sort(crystal,crystal+n,cmp);

    int mid;
    if(jo(n))
    {
        mid = crystal[n/2-1];
        cout << num(mid,n/2-1,m,crystal);
    }
    else
    {
        mid = crystal[n/2];
        cout << num(mid,n/2,m,crystal);
    }



    return 0;
}
