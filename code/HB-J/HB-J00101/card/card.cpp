
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node
{
    int x,y;
}a[500005];
int m[100005];
int y[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x;
        a[i].y=0;
    }
    int t=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(y[a[j].x]=1)
            {
                y[a[j].x]=1;
                m[j-i]=a[j].x;
                t++;

            }

        }
    }
    return 0;
}
