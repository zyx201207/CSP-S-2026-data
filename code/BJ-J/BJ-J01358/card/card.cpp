#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int t[300005]={0};
    if(m<=2)
    {
        if(m==1)
            cout<<n;
        else
        {
            int ans1=0,ans2=0;
            for(int k=1;k<=n;k++)
            {
                int x=0,y=0;
                for(int i=k;i<=n;i++)
                {
                    if(a[i]==1)
                    {
                        x++;
                        if(x==2 or y==2)
                        {
                            x=0;y=0;
                        }
                    }
                    else if(a[i]==2)
                    {
                        y++;
                        if(y==2 or x==2)
                        {
                            x=0;y=0;
                        }
                    }
                }
                ans1+=x;ans2+=y;
                cout<<ans1<<endl<<ans2;
            }
            cout<<ans1<<" "<<ans2;
        }
    }
    return 0;
}
