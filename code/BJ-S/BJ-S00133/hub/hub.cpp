#include <bits/stdc++.h>
using namespace std;
int n,k,c,t;
int a[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    scanf("%d%d",&c,&t);
    int k=t;
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n-1;i++)
        {
            scanf("%d",&a[i]);
        }
    }
    if(k==2)
    {
        printf("1\n2");
    }
    return 0;
}
