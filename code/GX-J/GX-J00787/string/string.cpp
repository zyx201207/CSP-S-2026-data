#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    int a[100];
    double c[100];
    for(int i=0;i<=n;i++)
    {

        cin>>a[i];
        cin>>c[i];
    }
    int m[100];
    for(int i=0;i<=n;i++)
    {
        for(int l=1;l<=a[i];l++)
        {
            if(a[i]>=2)
            {
                for(int o=0;o<=a[i];o++)
                {
                    m[i]=c[i];
                }
            }
            else{
                    m[i]=c[i];

            }
        }
    }
    return 0;
}
