#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
    int a,b;
};
int f (int x,int  y)
{
    return x&y;
}
int d(int x)
{
    int i=2,bj=0;
    while(i<=x)
    {
        i*=2;
        bj++;
    }
    return bj+1;
}
int z(int x)
{
    int bj=0,g=d(x);
    for(int i=1;i<=g;i++)
    {
        if(x%2==1)
        {
            bj++;
            x=(x-1)/2;
        }
    }
    return bj;
}
bool cmp(node x,node y)
{
    return x.b>y.b;
}
int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    node str[200005];
    for(int i=1;i<=n;i++) cin>>str[i].a;
    for(int i=1;i<=n;i++)
    {
        str[i].b=z(str[i].a);
    }
    sort(str+1,str+1+n,cmp);
    int sum=str[1].a;
    for(int i=2;i<=m;i++)
    {
        sum=f(sum,str[i].a);
    }
    cout <<sum;
    return 0;
}
/*
0011
1111
1100
*/
