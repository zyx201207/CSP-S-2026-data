#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    int v[t];
    for(int i=0;i<t;i++)
    {
        v[i]=0;
    }
    for(int i=0;i<t;i++)
    {
        cin>>n>>d;
        int x[n];
        for(int j=0;j<n;j++)
        {
            cin>>x[j];
        }
        for(int j=0;j<n;j++)
        {
            int q=0;
            for(int z=1;z<=d;z++)
            {
                for(int y=0;y<n;y++)
                {
                    if(x[j]+z==x[y])
                    {
                        q++;
                    }
                }
            }
            if(q==2)
            {
                v[i]++;
            }
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<v[i]-1<<endl;
    }
    return 0;
}
