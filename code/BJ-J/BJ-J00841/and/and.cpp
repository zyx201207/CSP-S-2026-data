#include <bits/stdc++.h>
using namespace std;

int n,m,a[105],b[105],maxx=0,j=0,p=0,q=0,ans=0;
bool stu = false;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];

    }
    sort(a+1,a+n+1,cmp);
    int p = n;
    while(p>=m)
    {
        int x=0;
        while(b[maxx-j]<=m)
        {
            for(int i=1;i<=m;i++)
            {
                int z=a[i];
                while(z>0)
                {
                    b[x]+=z%2;
                    if(x>maxx)  maxx=x;
                    x++;
                    z/=2;
                }
            }
            j++;
        }
        maxx-=j;
        ans+=pow(2,maxx);
        p=0;
        while(a[p]>=pow(2,maxx)) p++;
        for(int i=1;i<=p;i++)
        {
            a[i]-=pow(2,maxx);
            b[i]=0;
        }
    }
    cout << p;
    for(int i=1;i<=p;i++) cout << b[i] << ' ';
    cout << ans;
    return 0;
}
