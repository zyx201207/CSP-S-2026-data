#include <bits/stdc++.h>
using namespace std;
struct node
{
    int num;
    char c;
}a[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %c",&a[i].num,&a[i].c);
    }
    for(int l=1,r=n;l<=r;)
    {
        if(a[l].c!=a[r].c)
        {
            if(a[l].num>a[r].num)
            {
                sum+=a[r].num;
                a[l].num-=a[r].num;
                a[r].num=0;
                r--;
            }
            else if(a[r].num>a[l].num)
            {
                sum+=a[l].num;
                a[r].num-=a[l].num;
                a[l].num=0;
                l++;
            }
            else
            {
                sum+=a[l].num;
                a[l].num=a[r].num=0;
                l++;
                r--;
            }
        }
        else
        {
            if(a[l].num>a[r].num)
            {
                a[l].num-=a[r].num;
                a[r].num=0;
                r--;
            }
            else if(a[r].num>a[l].num)
            {
                a[r].num-=a[l].num;
                a[l].num=0;
                l++;
            }
            else
            {
                a[l].num=a[r].num=0;
                l++;
                r--;
            }
        }
    }
    printf("%lld",sum);
    return 0;
}
