#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200005];
long long a1[200005][35];
long long a2[35];
bool cmp(long long x,long long y)
{
    return x > y;
}
void ejz(int i,long long a)
{
    int ai=1,aa=a;
    while(1)
    {
        a1[i][ai]=aa%2;
        aa/=2;
        ai++;
        if(aa == 0)
        {
            break;
        }
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i <= n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i <= m;i++)
    {
        ejz(i,a[i]);
    }
    for(int i=1;i <= 30;i++)
    {
        a2[i]=a1[1][i];
    }
    for(int i=2;i <= m;i++)
    {
        for(int j=1;j <= 30;j++)
        {
            if(a1[i][j] == 1&&a2[j] == 1)
            {
                a2[j]=1;
            }
            else
            {
                a2[j]=0;
            }
        }
    }
    for(int i=30;i >= 1;i--)
    {
        ans+=a2[i]*pow(2,i-1);
    }
    cout<<ans;
    return 0;
}
