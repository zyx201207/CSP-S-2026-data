#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans=0;
int a[200010];

void dfs(int step,int took,int num)
{
    if(step>n)
    {
        if(took==m)
        {
            ans=max(ans,num);
        }
        return;
    }

    int step_more=n-step+1;
    if(took+step_more<m)return;
    if(took>m)return;

    dfs(step+1,took+1,num&a[step]);
    dfs(step+1,took,num);
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;

    if(m==1)
    {
        int maxn=-1e9;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;

            maxn=max(maxn,x);
        }
    }
    else if(m==2)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];

            for(int j=1;j<i;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }

        cout<<ans<<endl;
    }
    else if(n==m)
    {
        int x;
        cin>>x;

        ans=x;
        for(int i=2;i<=n;i++)
        {
            cin>>x;
            ans=ans&x;
        }

        cout<<ans<<endl;
    }
    else
    {
        bool flagA=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];

            long long po=1;
            while(flagA)
            {
                po*=2;

                if(a[i]==po-1)break;

                if(po==2147483648)
                {
                    flagA=false;
                    break;
                }
            }
        }

        if(flagA)
        {
            sort(a+1,a+n+1,greater<int>());
            cout<<a[m]<<endl;
            return 0;
        }

        dfs(1,0,2147483647);

        cout<<ans<<endl;
    }
    return 0;
}
