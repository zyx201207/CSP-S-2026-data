#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",std.in);
    freopen("crystal.out","w",std.out);
    int n,m,ans=0,c,d=0,e=-1,sj;
    long long a[100005],al[100005],v[10005];
    vector<int> b(10005,0);
    srand(time(0));
    cin>>n>>m;
    int f=n+1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        al[i]=a[i];
    }
    for(int nl=0;nl<100;nl++)
    {
        for(int pp=0;pp<n;pp++)
        {
            a[pp]=al[pp];
        }
        for(int i=0;i<m;i++)
        {
            while(f>=n)
            {
                srand(time(0));
                sj=rand();
                f=sj%10;
            }
            a[f]++;
        }
        for(int k=0;k<n;k++)
        {
            for(int l=k+1;l<n;l++)
            {
                if(a[k]==a[l])
                {
                    d++;
                }
            }
            b[k]=d;
            if(d>0)
            {
                int op=1;
            }
            d=0;
        }
    }




    for(int z=0;z<n;z++)
    {
        e=max(e,b[z]);
    }
    if(e==0)
    {
        cout<<e;
    }
    if(e>0)
    {
        cout<<e+1;
    }
    return 0;
}
