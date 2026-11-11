#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[5000005],zl[5000005],x[5000005];

bool Find(int l)
{
    if(l==1)
    {
        return false;
    }
    for(int i=1;i<=l;i++)
    {
        if(x[i]==x[l])
        {
            return true;
        }
    }
    return false;
}
int Find2(int l)
{
    for(int i=1;i<=l;i++)
    {
        if(x[i]==x[l])
        {
            return i;
        }
    }
}
int sc(int r,int l)
{
    while(1)
    {
        if(l<r)
        {
            return l;
        }
        l--;
    }
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    for(int h=1;h<=n;h++)
    {
        int l=0;
        for(int i=h;i<=n;i++)
        {
            l++;
            x[l]=p[i];

            if(Find(l))
            {
                int t=Find2(l);

                l=sc(t,l);
                l++;
                x[l]=p[i];
            }
            else{

            }

        }
        for(int i=1;i<=l;i++)
        {

            zl[x[i]]++;
        }
        for(int i=1;i<=5000005;i++)
        {
            x[i]=0;
        }
    }

    for(int i=1;i<=m;i++)
    {
        cout<<zl[i]<<' ';
    }
    return 0;
}
