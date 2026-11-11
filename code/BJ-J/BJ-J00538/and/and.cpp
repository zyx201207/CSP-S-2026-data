#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[200005][35];
long long po[35];
bool vis[200005];
long long x,ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ans=0;
    po[0]=1ll;
    for(int i=1;i<=32;i++) po[i]=po[i-1]*2ll;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        int cnt=0;
        while(x)
        {
            cnt++;
            num[i][cnt]=x%2;
            x/=2;
        }
    }
    for(int i=32;i>=1;i--)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==0)
            {
                sum+=num[j][i];
            }
        }
        if(sum>=m)
        {
            for(int k=1;k<=n;k++)
            {
                if(num[k][i]==0) vis[k]=1;
            }
            ans+=po[i-1];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
