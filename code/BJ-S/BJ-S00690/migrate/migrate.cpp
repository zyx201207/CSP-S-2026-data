#include <bits/stdc++.h>
using namespace std;
int n,d;
int x[10086];
int k=0,l=INT_MAX,ans=0;
void f(int st,int nd,int len)
{
    for(int i=st+1;i<=nd;i++)
    {
        if(x[i]-x[st]<=d)
        {
            if(i==nd)
            {
                if(len+1<l)
                {
                    l=len+1;
                    k=1;
                    return;
                }
                if(len+1==l)
                {
                    k++;
                    return;
                }
            }
            else
            {
                f(i,nd,len+1);
            }
        }
        else
        {
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=n;j>=i;j--)
            {
                f(i,j,0);
            }
            if(k==2)
                ans++;
            k=0;l=INT_MAX;
        }
        cout<<ans-1<<'\n';
        ans=0;
    }
    return 0;
}
