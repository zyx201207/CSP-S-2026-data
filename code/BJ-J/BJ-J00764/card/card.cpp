#include<bits/stdc++.h>
using namespace std;
int n,m,b[5005],vis[3005],cnt;
vector<int> a;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int q=1;q<=n;q++)
    {
        a.clear();
        for(int k=q;k<=n;k++)
        {
            int num=b[k];
            cnt=0;
            for(int i=0;i<a.size();i++) if(a[i]==num) while(a.size()>i) a.pop_back();
            a.push_back(num);
        }
        for(int i=0;i<a.size();i++) vis[a[i]]++;
    }
    for(int i=1;i<=m;i++) cout<<vis[i]<<" ";
    return 0;
}
