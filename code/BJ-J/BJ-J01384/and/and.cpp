#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool h[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long maxx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    long long cnt=0;
    while(maxx)
    {
        maxx/=2;
        cnt++;
    }
    cnt--;
    long long sum=0;
    for(long long i=cnt;i>=0;i--)
    {
        int idx=0;
        for(int j=1;j<=n;j++)
        {
            if(h[j])continue;
            if(((a[j]>>i)%2)==1)idx++;
        }
        if(idx<m)continue;
        for(int j=1;j<=n;j++)
        {
            if(h[j])continue;
            if(((a[j]>>i)%2)==0)h[j]=1;
        }
        sum+=1<<i;
    }cout<<sum;
    return 0;
}

