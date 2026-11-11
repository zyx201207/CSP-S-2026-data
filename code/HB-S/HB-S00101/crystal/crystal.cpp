#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long n;
long long m;
vector <int> a;
vector <int> num;
vector <int> sum;
int fin = -10;
int main()
    {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(long long i = 1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a[1],a[n]);

    for(long long i = 1;i<=n;i++)
    {
        for(long long j = i-1;j>=1;j--)
        {

            sum[i] += a[i]-a[j];
            num[i]++;if(sum[i]>m)
            {
                num[i]--;
                break;

            }
        }
    }

    for(long long i = 1;i<=n;i++ )
    {
        fin = max(fin,num[i]);
    }

    cout<<fin;
    return 0;
}
