#include <bits/stdc++.h>
using namespace std;
int book[200005];
int a[200005];
int sum;
int n,m;
int f(int k,int cnt)
{
    if(k>m)
    {
        sum=max(sum,cnt);
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            int o=cnt&a[i];
            f(k+1,o);
            book[i]=0;
        }
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
    }
    int jk=0;
    for(int i=1;i<=n;i++)
    {
        book[i]=1;
        int g=f(2,a[i]);
        book[i]=0;
        jk=max(jk,g);
    }
    cout<<jk;
    return 0;
}
