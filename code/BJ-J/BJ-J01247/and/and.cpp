#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
int b[N][30];
int yix,Tima;
struct Node
{
    int bian;
    int rutim;
} cus[N];
bool cmp(Node &tmp_1,Node &tmp_2)
{
    return tmp_1.rutim>tmp_2.rutim;
}
long long ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        long long x=a[i];
        for(int j=1;j<=30;j++)
        {
            if(x==0) b[i][j]=0;
            else b[i][j]=x%2,x/=2;
        }
        cus[i].bian=i;
    }
    for(int j=30;j;j--)
    {
        if(yix<m)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(b[i][j]) cnt++;
            }
            if(cnt>=m)
            {
                Tima=j;
                for(int i=1;i<=n;i++)
                {
                    if(b[i][j]) cus[i].rutim=j;
                }
            }
            yix=cnt;
        }
        if(yix>=m) break;
    }
    if(yix<m)
    {
        cout<<0;
        return 0;
    }
    if(yix==m)
    {
        sort(cus+1,cus+n+1,cmp);
        ans=a[cus[1].bian];
        for(int i=2;i<=m;i++) ans&=a[cus[i].bian];
        cout<<ans;
        return 0;
    }
    for(int j=Tima-1;j;j--)
    {
        if(yix==m) break;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i][j] && cus[i].rutim) cnt++;
        }
        if(cnt>=m)
        {
            for(int i=1;i<=n;i++)
            {
                if(!b[i][j] && cus[i].rutim) cus[i].rutim=0;
            }
            yix=cnt;
        }
    }
    sort(cus+1,cus+n+1,cmp);
    ans=a[cus[1].bian];
    for(int i=2;i<=m;i++) ans&=a[cus[i].bian];
    cout<<ans;
    return 0;
}
