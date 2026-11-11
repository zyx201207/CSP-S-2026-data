#include<bits/stdc++.h>

using namespace std;


unsigned long long n,m,mx = -1;
int a[1000000005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    if(m == 1)
    {
        for(int i = 0;i<n;i++)
        {
            if(a[i]>mx)mx = a[i];
        }
        cout<<mx;
        return 0;
    }
    if(m == n)
    {
        long long temp = a[0];
        for(int i = 0;i<n;i++)
        {
            temp = a[i] and a[i+1];
        }
        cout<<temp;
        return 0;
    }

    return 0;
}
