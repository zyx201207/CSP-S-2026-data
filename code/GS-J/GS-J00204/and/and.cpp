#include<iostream>
#include<cstdio>

using namespace std;
int n,m,a[200005];
long long ans=0;
void dfs(int step,long long ma,int stepm)
{

    if(stepm==m)
    {
        ans=max(ma,ans);
        return;
    }
    if(step>n)
    {
        return;
    }
    //cout<<step<<endl<<ma<<endl<<a[step]<<endl<<stepm<<endl<<endl<<endl;
    int k=ma&a[step];
    dfs(step+1,k,stepm+1);
    dfs(step+1,ma,stepm);

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
    dfs(1,4294967295,0);
    cout<<ans;
    return 0;
}

