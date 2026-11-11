#include <bits/stdc++.h>
using namespace std;
bool book[200002];
long long a[200002],num;
int m,n;
void dfs(int x,long long y,long long tmp)
{
    if(x==1)
    {
        num=max(num,(tmp&a[y]));
        return;
    }
    for(int j=1;j<=n;j++)
    {
        if(book[j]==false)
        {
            book[j]=true;
            dfs(x-1,j,(tmp&a[y]));
            book[j]=false;
        }
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
    for(int i=1;i<=n;i++)
    {
        book[i]=true;
        dfs(m,i,a[i]);
        book[i]=false;
    }
    cout<<num;
    return 0;
}
