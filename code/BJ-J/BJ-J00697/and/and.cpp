#include <bits/stdc++.h>
using namespace std;
long long n,m,a[300005],mx=-1,ans;
bool st[500005];
vector<int> v[500005],last;
void push(int x,int i)
{
    while(x)
    {
        v[i].push_back(x&1);
        x>>=1;
    }
}
long long turn()
{
    long long res=1,sum=0;
    int len=last.size();
    for(int i=len-1;i>=0;i--)
    {
        int x=last[i];
        sum+=x*res;
        res<<=1;
    }
    return sum;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        push(a[i],i);
        long long len=v[i].size();
        mx=max(mx,len);
    }
    for(int i=1;i<=n;i++)
    {
        while(v[i].size()<=mx)v[i].push_back(0);
    }
    for(int i=mx-1;i>=0;i--)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            if(v[j][i]==1 && !st[j])sum++;
        }
        if(sum>=m)
        {
            last.push_back(1);
            for(int j=1;j<=n;j++)
            {
                if(v[j][i]!=1)st[j]=1;
            }
        }
        else
        {
            last.push_back(0);
        }
    }
    cout<<turn();
}
