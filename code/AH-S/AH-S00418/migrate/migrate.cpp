#include<bits/stdc++.h>
using namespace std;
int c,t,s=0,n,d,ans=0,m=2147483640;
int x[2000100]={0};
void dfs(int a,int b,int h)
{
    if(a==b)
    {
        if(h<m)
        {
            s=1;
            m=h;
            cout<<a<<" "<<b<<" "<<h<<endl;
        }
        else if(m==h)
        {
            s++;
            cout<<a<<" "<<b<<" "<<h<<endl;
        }
        return ;
    }
    if(h>m)return ;
    for(int i=a+1;i<=b;i++)
    {
        if(x[i]-x[a]>d)break;
        dfs(i,b,h+1);
    }
    return ;
}
int main(void)
{
    freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        ans=0;
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&x[i]);
        }
        for(int j=1;j<n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                s=0;
                m=2147483640;
                dfs(j,k,0);
                if(s==2)
                {
                    ans++;
                    //cout<<j<<" "<<k<<" "<<s<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
