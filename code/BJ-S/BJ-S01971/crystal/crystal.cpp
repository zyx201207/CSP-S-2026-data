#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    freopen("crystal","r",stdin);
    freopen("crystal","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int i=m;i>0;i--)
        {
            if(m>0)
            {
                a[i]+=m-(m-1);
                m--;
                if(a[i]==a[i+1]||a[i]==a[i+2])
                {
                    ans+=1;
                }
            }
            else
            {
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}