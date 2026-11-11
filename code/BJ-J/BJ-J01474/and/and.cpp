//T3
#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200010];
long long ta[40];
long long cnt=0;
vector<int> e[5];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=0;i<=39;i++) ta[i]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long temp=1;
    for(int i=1;i<=31;i++) temp=temp*2;
    for(int i=1;i<=n;i++) e[1].push_back(i);
    for(int i=31;i>=0;i--)
    {
        if(cnt>=m)
        {
            e[1].clear();
            for(int t:e[2]) e[1].push_back(t);
        }
        e[2].clear();
        cnt=0;
        for(int t:e[1])
        {
            if(a[t]&temp)
            {
                cnt++;
                e[2].push_back(t);
            }
        }
        if(cnt>=m) ta[i]=1;
        temp=temp/2;
    }
    temp=1;
    long long ans=0;
    for(int i=0;i<=30;i++)
    {
        if(ta[i]) ans+=temp;
        temp*=2;
    }
    cout<<ans;
    return 0;
}