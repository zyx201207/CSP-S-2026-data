#include<bits/stdc++.h>
using namespace std;
long long a[10000005],b[1000005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1; i<= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i<= n;i++)
    {

        for(int j = i;j <= m;j++)
        {
            int cc=a[j];
            cc=cc&a[j+1];
            b[i]=cc;
        }
    }
    int maxx=-9999;
    for(int i = 1;i <= n;i++)
    {
        if(maxx<b[i])
            maxx=b[i];
    }
    cout << maxx;
    return 0;
}
