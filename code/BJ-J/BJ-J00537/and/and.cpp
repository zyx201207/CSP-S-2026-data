#include <bits/stdc++.h>
using namespace std;
int a[200001];
bool b[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=29;i>=0;i--)
    {
        int x=(1<<i),cnt=0;
        for(int j=1;j<=n;j++)
        if(!b[j])
        {
            cnt+=((a[j]&x)>0);
        }
        if(cnt>=m)
        {
            ans|=x;
            for(int j=1;j<=n;j++)
            if(!b[j])
            {
                if((a[j]&x)==0)
                    b[j]=1;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
