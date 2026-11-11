#include<bits/stdc++.h>
using namespace std;
const  int maxn = 1e7+5;
long long ans[maxn],c,t,n,d,x[maxn];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int v = 1;v<=t;v++)
    {
        cin>>n>>d;
        for(int j = 1;j<=n;j++)
        {
            cin>>x[j];
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = i;j<=n;j++)
            {
                int b = x[j]-x[i];
                if(b<=2*d-1 && b>d && (j-i)%2==1 && x[j-1]-x[i]<=d && x[j]-x[j-1]<=d) ans[v]++;
            }
        }
    }
    for(int i = 1;i<=t;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
