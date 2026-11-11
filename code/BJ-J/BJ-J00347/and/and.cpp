#include <bits/stdc++.h>
using namespace std;

long long a[200010];//&
long long st[50];
map<long long,long long> mp;
long long maxn=0;
long long n,m;
bool cmp(long long x,long long y)
{
    return x > y;
}
void dfs(int i,int x,long long ad)
{
    if(x>=m)
    {
        //cout << "ad:" << ad << "!" <<endl;
        maxn=max(maxn,ad);
        return;
    }
    if(i>n) return;
    //cout << a[i] << " ";
    dfs(i+1,x+1,ad&a[i]);
    dfs(i+1,x,ad);
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    st[0]=1;
    for(int i=1;i<=32;i++)
    {
        st[i]=st[i-1]*2;
        mp[st[i]]=1;
    }
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(mp[a[i]]==1) flag++;
    }
    if(flag==n)
    {
        sort(a+1,a+n+1,cmp);
        cout << a[m];
        return 0;
    }
    /*
    for(int i=1;i<=n;i++)
    {
        dfs(i,0,a[i]);
    }*/
    dfs(1,0,st[32]-1);
    cout << maxn <<endl;
    return 0;
}
