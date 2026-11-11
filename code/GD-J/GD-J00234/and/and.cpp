#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[35]={1};
bool cmp(int c,int d)
{
    return c>d;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        printf("%d",a[i]);
    int t=1;
    for(int i=1;i<=30;i++)
    {
        t*=2;
        b[i]=t-1;
    }

    return 0;
}
