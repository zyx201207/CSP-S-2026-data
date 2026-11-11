#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ok[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        ok[i]=1;
    }
    long long ans=0;
    for(int i=30; i>=0; i--)
    {
        int num=0;
        for(int j=1; j<=n; j++)
        {
            if(ok[j]&&(a[j]&(1<<i)))
            {
                //cout<<j<<"@"<<endl;
                num++;
            }
        }
        if(num>=m)
        {
            for(int j=1; j<=n; j++)
            {
                if(ok[j]&&!(a[j]&(1<<i)))
                {
                    //cout<<j<<"#"<<endl;
                    ok[j]=0;
                }
            }
            //cout<<(1<<i)<<endl;
            ans+=(1<<i);
        }
    }
    cout<<ans<<endl;
}
