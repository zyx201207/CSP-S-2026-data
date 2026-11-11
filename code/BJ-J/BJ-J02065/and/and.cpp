#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool b[200005][31];
bool c[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        c[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int x=a[i],j=30;
        while(x>0)
        {
            if(x&1)b[i][j]=1;
            x=x>>1;
            j--;
        }
    }
    unsigned long long ans=0;
    for(int i=1;i<=30;i++)
    {
        vector<int> k;
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(!c[j])continue;
            if(b[j][i])
            {
                cnt++;
            }
            else
                k.push_back(j);
        }
        if(cnt>=m)
        {
            for(int j=0;j<k.size();j++)
            {
                c[k[j]]=0;
            }
            ans+=pow(2,(30-i));
        }
    }
    cout<<ans;
    return 0;
}
