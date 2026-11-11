#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,a[N],m;
int ans[N];
bool book[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(book,0,sizeof book);
        stack <int> s;
        for(int j=i;j<=n;j++)
        {
            if(book[a[i]]==0) s.push(a[i]),ans[a[i]]++,book[a[i]]=1;
            else
            {
                while(s.top()!=a[i])
                {
                    book[s.top()]=0;
                    ans[s.top()]--;
                    s.pop();
                }
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
