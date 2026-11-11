#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string ten_to_two(int x)
{
    string ans,s;
    int i=0;
    while(x)
    {
        ans[i]=x%2;
        x/=2;
        i++;
    }
    //int j=0;
    //while(i+1)
    //{
    //    ans[j]=s[i-1];
      //  j++;
        //i--;
    //}
    return ans;
}
ll a[200010];
int n,m;
int dfs(int x,int tot,)
{
    if(x==m)
    {
        return a[x]&
    }
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
    
    return 0;
}

