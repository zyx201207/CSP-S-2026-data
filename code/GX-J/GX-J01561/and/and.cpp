#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,f;
    cin >> m >> n;
    int a[200005];
    int z[200005];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int j=0;j<a.size;j++)
    {
        for(int h=0;h<m;h++)
        {
            f = a[j] and a[j+1];
            z[j]=f;
        }
    }
    for(int k=0;k<z.size();k++)
    {
        if(z[k]>[k+1])
        {
            maxn=z[k];
        }
        else{
            maxn=z[k+1];
        }
    }
    return 0;
}
