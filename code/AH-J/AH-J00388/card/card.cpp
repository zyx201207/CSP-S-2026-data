#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
//注意先审题，再写，不要死磕，不要用复杂算法,记得释放注释检查

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n=0,m=0;
    cin >> n >> m;
    vector<int> c(n+1),lst(m+1),ans(m+1);
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
        lst[c[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=i;k<=n;k++)
        {
            ans[c[k]]++;
            k=lst[c[k]];
        }
    }
    for(int i=1;i<=m;i++)cout << ans[i] << " ";
    return 0;
}
