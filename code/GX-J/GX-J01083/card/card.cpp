#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[50005],b[50005],c[50005],e[50005];//all,wei,cun,end
    cin>>n>>m;
    fill(e,e+n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int l=0;l<n;l++)
    {
        fill(b,b+n,-1);
        for(int i=l;i<n;i++)
        {
            c[i]=a[i];
        }
        for(int i=l;i<n;i++)
        {
            if(b[a[i]]!=-1)
            {
                for(int j=b[a[i]];j<i;j++)
                {
                    b[c[j]]=-1;
                    c[j]=-1;
                }
            }
            b[a[i]]=i;
        }
        for(int i=l;i<n;i++)
        {
            //cout<<c[i]<<" ";
            if(c[i]!=-1)
            {
                e[c[i]]++;
            }
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<e[i]<<" ";
    }
    return 0;
}

