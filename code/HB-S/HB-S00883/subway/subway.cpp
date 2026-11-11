#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    int arr[c+5];
    for(int i=1;i<=c;i++)
    {
        cin>>arr[i];
    }
    int z[b+5][100005],t[b+5][100005],r[b+5];
    for(int j=1;j<=b;j++)
    {
        int o;
        cin>>o;
        r[j]=o;
        for(int i=1;i<=o;i++)
        {
            cin>>z[j][i]>>t[j][i];
        }

    }
    int q[e+5],zh[e+5];
    for(int i=1;i<=e;i++)
    {
        cin>>q[i]>>zh[i];
    }
    for(int i=1;i<=e;i++)
    {
        long long sun=0;
        int qd=q[i],zd=zh[i];
        sun=arr[qd]+arr[zd];
        int s=0,su=0;
        for(int j=1;j<=b;j++)
        {
            for(int k=1;k<=r[j];k++)
            {
                if(z[j][k]==qd&&su==0)
                {
                    su++;
                    sun+=t[j][k];

                }
                else if(z[j][k]==zd&&s==0)
                {
                    sun+=t[j][k];
                    s++;
                }
            }
        }
        cout<<sun<<endl;

    }
    return 0;
}
