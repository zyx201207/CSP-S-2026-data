#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005],lt[500005],rt[500005],pos;
unordered_map<int,int> ump,upm;
bool f(){
    for (int i=2;i<=n;i++)
    {
        if (a[i]<a[i-1])
        {
            return false;
        }
    }
    return true;
}
void solve(){
    for (int i=1;i<=n;)
    {
        if (a[i]==a[i+1])
        {
            lt[++pos]=i;
            while (a[i]==a[i+1]&&i<=n)
            {
                i++;
            }
            rt[pos]=i-1;
            cnt[a[rt[pos]]]=rt[pos];
        }
        else
        {
            i++;
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (f()&&n>500)
    {
        solve();
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        ump.clear();
        for (int j=i;j<=n;j++)
        {
            if (ump[a[j]])
            {
                for (int k=ump[a[j]];k<=j;k++)
                {
                    ump[a[k]]=0;
                }
            }
            ump[a[j]]=j;
        }
        for (auto j:ump)
        {
            if (j.second)
            {
                cnt[j.first]++;
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
