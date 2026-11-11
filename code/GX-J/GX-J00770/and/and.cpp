#include<bits/stdc++.h>
using namespace std;
int cdt=0,cd[200010];
string jz(int x)
{
    cdt++;
    string xx,t=" ";
    int cnt=0;
    while(x>0)
    {
        t+=x%2;
        x/=2;
        cnt++;
        cd[cdt]++;
    }
    for(int i=cnt-1;i--;i>=0)
    {
        xx+=t[i];
    }
    return xx;
}
int jz2(string x)
{
    int k=1,xx=0;
    for(int i=strlen;i>=1;i--)
    {
        xx+=k*(x[i]-"1");
    }
    return xx;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0,a[200010],vis[200010];
    string b[200010],ejz;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=jz(a[i]);
        vis[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        int sl=1;
        ejz=b[i];
        if(n-i+1<m)
        {
            break;
        }
        while(sl<m)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(vis[j]==0)
                {
                    vis[j]=1;
                    for(int k=1;k<=cd[j];k++)
                    {
                        if(b[j][k]!=ejz[k])
                        {
                            ejz[k]=0;
                        }
                    }
                    maxn=max(maxn,jz2(ejz));
                }
            }
        }
    }
    cout<<maxn;
    return 0;
}
