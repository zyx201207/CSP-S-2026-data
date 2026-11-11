#include<bits/stdc++.h>
using namespace std;

int a[200005],ans=0x7fffffff,cc=0,n,d;

void dfs(int x,int step,int l)
{
    if(x>l) return;
    if(x==l)
    {
        if(step<ans)
        {
            ans=step;
            cc=1;
        }
        else if(step==ans) cc++;
        return;
    }
    for(int i=x+1;i<=n;i++)
    {
        if((a[i]-a[x])<=d)
        {
            dfs(i,step+a[i]-a[x],l);
        }
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cc=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int anss=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                cc=0;
                ans=0x7fffffff;
                dfs(j,0,k);
                if(cc==2) anss++;
            }
        }
         cout<<anss<<endl;
    }

    return 0;
}

