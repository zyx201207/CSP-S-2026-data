#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010];
long long nxt[2000005][22],pre[2000005][22],ans=0ll;
bool check(int x,int y,int z)
{
    if(a[z]-a[y-1]<=d||a[y+1]-a[x]<=d) return 0;
    else return 1;
}
int fpre(int x)
{
    int sum=1;
    for(int j=21;j>=0;j--)
    {
        if(pre[x][j]!=0)
        {
            sum+=(1<<j);
            x=pre[x][j];
        }
    }
    return sum;
}
int fnxt(int x)
{
    int sum=1;
    for(int j=21;j>=0;j--)
    {
        if(nxt[x][j]!=0)
        {
            sum+=(1<<j);
            x=nxt[x][j];
        }
    }
    return sum;
}
void work(int x,int z)
{
    int y=nxt[x][0];
    if(y==0||z==0||x==y||y==z||y==-1||z==-1) return;
    if(a[z]-a[y-1]<=d&&a[y+1]-a[x]>d&&a[z]-a[y-2]>d)  
    {
        bool t1=(check(pre[x][0],x,y-1)||pre[x][0]==0);
        bool t2=(check(y,z,nxt[z][0])||nxt[z][0]==0);
        if(t1&&t2) ans+=1ll*fpre(x)*fnxt(z);
        else if(t1) ans+=1ll*fpre(x);
        else if(t2) ans+=1ll*fnxt(z);
        else ans++;
    }
    else if(a[z]-a[y-1]>d&&a[y+1]-a[x]<=d&&a[y+2]-a[x]>d) 
    {
        bool t1=(check(pre[x][0],x,y)||pre[x][0]==0);
        bool t2=(check(y+1,z,nxt[z][0])||nxt[z][0]==0);
        if(t1&&t2) ans+=1ll*fpre(x)*fnxt(z);
        else if(t1) ans+=1ll*fpre(x);
        else if(t2) ans+=1ll*fnxt(z);
        else ans++;
    }
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0ll;
        cin>>n>>d;
        for(int j=0;j<=21;j++)
        {
            for(int i=1;i<=n;i++) nxt[i][j]=pre[i][j]=0;
        }
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            int l=i,r=n+1,mid;
            while(l+1<r)
            {
                mid=(l+r)/2;
                if(a[mid]-a[i]<=d) l=mid;
                else r=mid;
            }
            if(i!=l) nxt[i][0]=l;
            l=0,r=i,mid;
            while(l+1<r)
            {
                mid=(l+r)/2;
                if(a[i]-a[mid]<=d) r=mid;
                else l=mid;
            }
            if(i!=r) pre[i][0]=r;
        }
        for(int j=1;j<=21;j++)
        {
            for(int i=1;i<=n;i++) nxt[i][j]=nxt[nxt[i][j-1]][j-1],pre[i][j]=pre[pre[i][j-1]][j-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int r=nxt[i][0]+1;r<=nxt[i][1];r++) work(i,r);
        }
        cout<<ans<<'\n';
    }
}