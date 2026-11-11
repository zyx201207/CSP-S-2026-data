#include <bits/stdc++.h>

using namespace std;
int n,m,ans;
int a[200005];
int v[200005];
void dfs(int sd,int ma,int pos)
{
    if(sd==m+1)
    {
        if(ans<ma)
        {
            ans=ma;
            return;
        }
    }
    for(int i=pos+1;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            if(sd==1)
            {
                ma=a[i];
            }
            dfs(sd+1,(ma&a[i]),i);
            v[i]=0;
        }

    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //cout << "Hello world!" << endl;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
