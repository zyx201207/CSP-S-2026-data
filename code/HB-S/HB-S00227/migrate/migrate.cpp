#include <bits/stdc++.h>
using namespace std;

const int NN=2e5+5;
int c,t,n,d,ans=0;
int x[NN]{}, h1, h2;

int sl(int a,int b)
{
    int cnt=0;
    h1=a*17;
    for (int i = a+1; i <= b; i++)
    {
        if(x[i]>x[a]+d && i-a>1)
        {
            cnt++;
            a=i-1;
            h1+=a*17;
        }
    }
    
    return cnt;
}
int sr(int a,int b)
{
    int cnt=0;
    h2=a*17;
    for (int i = a-1; i >= b; i--)
    {
        if(x[i]<x[a]-d)
        {
            cnt++;
            a=i+1;
            h2+=a*17;
        }
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while (t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }

        for (int i = 0; i < n-1; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int z1=sl(i,j);
                int z2=sr(j,i);
                if (z1==z2 && h1!=h2 && z1)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}