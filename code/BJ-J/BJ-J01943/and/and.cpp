#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ad(int a,int b)
{
    int ans=0;
    int i=1;
    while(a!=0&&b!=0)
    {
        if(a%2==1&&b%2==1)
        {
            ans+=i;
        }
        i*=2;
        a/=2;
        b/=2;
    }
    return ans;
}
int dfs(int i,int x,int g)
{
    if(g==m)
        return x;
    int mx=0;
    if(i>m)
        return 0;
    for(int j=i;j<n-m+i;j++)
    {
        mx=max(mx,dfs(j+1,ad(x,a[j]),g+1));
    }
    return mx;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<dfs(0,1073741824,0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
