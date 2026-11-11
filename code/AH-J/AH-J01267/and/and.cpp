#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool f[200005][35];
bool cmp(int x,int y)
{
    return x>y;
}
queue<int> q[35];
int t[200005];
int ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int p=0;
        int x=a[i];
        while(x)
        {
            int flag=x%2;
            f[i][++p]=(bool)(flag);
            x/=2;
        }
    }
    sort(a+1,a+1+n,cmp);
    int num=a[m];
    int pos=0;
    while(num)
    {
        pos++;
        num/=2;
    }
    int i;
    for(i=pos;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(f[j][i]==1)
            {
                q[i].push(j);
            }
        }
        if(q[i].size()>=m)
        {
            ans=pow(2,i-1);
            while(!q[i].empty())
            {
                int x=q[i].front();
                q[i].pop();
                t[x]=1;
            }
            break;
        }
    }
    i--;
    int now=1;
    for(int k=i;k>=1;k--)
    {
        for(int j=1;j<=n;j++)
        {
            if(f[j][k]==1)
            {
                if(t[j]==now)
                {
                    q[k].push(j);
                }
            }
        }
        if(q[k].size()>=m)
        {
            now++;
            ans+=pow(2,k-1);
            while(!q[k].empty())
            {
                int x=q[k].front();
                t[x]++;
                q[k].pop();
            }
        }
    }
    cout<<ans;
    return 0;
}
