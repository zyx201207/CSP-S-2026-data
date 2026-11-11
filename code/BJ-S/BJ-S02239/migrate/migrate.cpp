#include<bits/stdc++.h>
using namespace std;
int x[5050],c,t,cr[5050],be[5050];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d,z=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(n<4)
        {
            cout<<0;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                cr[i]=-1;
                be[i]=-1;
                for(int j=i+1;j<=n;j++)
                {
                    if(x[j]-x[i]<=d)
                    {
                        if(j>=i+2)
                        {
                            cr[i]=j;
                            be[j]=i;
                        }
                    }
                }
                //cout<<cr[i]<<" ";
            }
            for(int i=1;i<n;i++)
            {
                if(cr[i]!=-1)
                {
                    int k=0;
                    for(int j=i+1;j<cr[i];j++)
                    {
                        if(cr[j]>cr[i]&&cr[j]!=-1)
                        {
                            k++;
                            //cout<<endl<<i<<" "<<j<<" "<<z<<endl;
                        }
                        if(cr[j]==cr[j-1]&&cr[j]!=-1)
                        {
                            k=0;
                            break;
                        }
                    }
                    z+=k;
                }
            }
            cout<<z<<endl;
        }
    }
    return 0;
}
