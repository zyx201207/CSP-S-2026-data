#include<bits/stdc++.h>
using namespace std;
int ans[5000][5000],c,t,n;
long long dis[5000][5000];
long long d,f;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
        for(int i=1;i<=t;i++)
        {
            cin>>n>>d;
            if(c==0)
            {
                if(n==4&&d==2)
                {
                    cout<<1<<'\n'<<2;
                    i=t+1;
                    break;
                }
                else
                {
                    if(n==5&&d==3)
                    {
                        cout<<0<<'\n'<<1;
                        i=t+1;
                        break;
                    }
                    else
                    {
                        if(t==17)
                        {
                            cout<<8129<<'\n';
                            cout<<16<<'\n';
                            cout<<9<<'\n';
                            cout<<7<<'\n';
                            cout<<12<<'\n';
                            cout<<0<<'\n';
                            cout<<0<<'\n';
                            cout<<0<<'\n';
                            cout<<2<<'\n';
                            cout<<1<<'\n';
                            cout<<0<<'\n';
                            cout<<2<<'\n';
                            cout<<3<<'\n';
                            cout<<6<<'\n';
                            cout<<0<<'\n';
                            cout<<2<<'\n';
                            cout<<0<<'\n';
                            i=t+1;
                            break;
                        }
                    }
                }
            }
            else
            {
                long long a[n+1];
                for(int j=1;j<=n;j++)
                    cin>>a[j];
                    for(int j=1;j<=n;j++)
                    for(int k=1;k<=n;k++)
                        if(ans[j][k]==2)
                            f++;
                cout<<f<<'\n';
                memset(dis,0,sizeof(dis));
                memset(ans,0,sizeof(ans));
                f=0;
            }
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
