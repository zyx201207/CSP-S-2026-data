#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    string t;
}a[200005];
int n,l,r;
long long sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    l=1,r=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].t;
    }
    while(l<r)
    {
        int x=a[l].x;
        int y=a[r].x;
        if(a[l].t!=a[r].t)
        {
            sum+=min(x,y);
        }
        if(x==y)
        {
            l++;
            r--;
        }
        if(x<y)
        {
            a[r].x-=x;
            l++;
        }
        if(x>y)
        {
            a[l].x-=y;
            r--;
        }
    }
    cout<<sum;
    return 0;
}
