#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=-2e9;
int a[100010];
int c[100010];
void dfs(int step,int sum,int i)
{
    //cout<<step<<" "<<sum<<" "<<i<<endl;
    if(step>=m)
    {
        maxn=max(maxn,sum);
        return;
    }

    if(i>n)
        return;
    //xuan
    if(step==0)
        dfs(step+1,a[i],i+1);
    else
    {
        c[step]=a[i];
        dfs(step+1,sum&a[i],i+1);
    }

    //buxuan
    dfs(step,sum,i+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<maxn<<endl;
    return 0;
}
