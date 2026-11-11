#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
vector<int>s[N];
int a[N],f[N];
int ans[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=n;i>=1;i--)
    {
        s[i]=s[i+1];
        s[i].push_back(i);
        if (f[a[i]]==0) f[a[i]]=i;
        else s[i]=s[f[a[i]]];
        for (int j=0;j<s[i].size();j++) ans[a[s[i][j]]]++;
    }
    for (int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}
