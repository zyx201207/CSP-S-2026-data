#include<bits/stdc++.h>

using namespace std;
int c,t;
int n,k,ans=0;
int a[1000005][2];
bool flag[1000005];
bool ok=false;
void dfs(int p,int num)
{
    if(num<=0)return;
    for(int i=p;i<=n;i++)
    {
        flag[i]=1;
        flag[a[i][0]]=1;
        flag[a[i][1]]=1;
        dfs(a[i][0],num-1);
        dfs(a[i][1],num-1);
    }
}
bool judge(int x)
{
    dfs(1,x);
    for(int i=1;i<=n;i++)
        if(flag[i]==0)
            return false;
    return true;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {   
        cin>>n>>k;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n-1;i++)
        {
            int l,r;
            cin>>l>>r;
            a[l][1]=r;
            a[r][0]=l;
        }
        int l=1,r=n,mid=(l+r)>>1;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(judge(mid))
            {
                ans=mid;
                r=mid;
            }
            else
                l=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}