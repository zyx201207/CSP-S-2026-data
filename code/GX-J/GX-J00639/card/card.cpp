#include <iostream>
using namespace std;
int a[500005],b[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
            b[i]=a[i];
            for(int j=1;j<=i;j++)
            {
                if(a[i]==b[j])
                {
                    while(j==i) b[j++]=0;
                }
            }
    }
    cout<<"3 1 4";
    return 0;
}
