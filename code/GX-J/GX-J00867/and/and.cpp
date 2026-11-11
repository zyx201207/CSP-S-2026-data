#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main ()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long x=0,y;
    int q;
    for(int i=1;i<=n-m+1;i++)
    {
        y=0;
        for(int j=i+2;j<=n;j++)
        {
            y=a[i]&a[i+1];
            q=m-2;

            int e=j;
            while(q>0)
            {
                y=y&a[e];
                e++;
                q--;

            }
            if(x<y)
            {
                x=y;
            }
        }
    }
    printf("%d",x);


    return 0;
}
