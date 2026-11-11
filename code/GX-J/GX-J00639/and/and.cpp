#include <iostream>
using namespace std;
long long a[200005],b[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (a[i]>=a[j])
            {
                int k=a[i];
                a[i]=a[j];
                a[j]=k;
            }

        }
    }
    for (int i=1;i<=m-1;i++)
        b[i]=(a[i]&a[i+1]);
    cout<<b[m-1];
    return 0;
}
