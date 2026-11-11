#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int a,c,e[500005],f,g,h,i=0,j=1,o=0,l;
    cin>>a>>c;
    for(f=0;f<a;f++)
    {
        cin>>e[f];
    }
    if(a==1)
    {
        cout<<"1";
        return 0;
    }
    for(f=0;f<a;f++)
    {
        for(g=0;g<a-1;g++)
        {
            if(e[g]>e[g+1])
            {
                h=e[g+1];
                e[g+1]=e[g];
                e[g]=h;
            }
        }
    }
    for(f=1;f<a;f++)
    {
        j=1;
        o=0;
        for(g=f-1;g>-1;g--)
        {
            o=e[g]+o;
            if(o+c>j*e[f])
            {
                j++;
            }
            else if(o+c==j*e[f])
            {
                if(j>i)
                {
                    l=j+1;
                }
            }
            else if(j>i)
            {
                i=j;
            }
        }
    }
    if(l>i)
    {
        i=l;
    }
    cout<<i;
    return 0;
}
