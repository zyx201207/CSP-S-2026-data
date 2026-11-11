#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,c[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
cin>>n>>m;
if(n==1)
{
    cout<<n;
    return 0;
}
for(int i = 0;i < n;i++)
{
    cin>>c[i];
}
sort(c,c+n);
long long mx=LONG_MIN;
for(int j = 0;j < n-1;j++)
{
    ans=1;
    for(long long i =j+1;i <n;i++)
    {
        long long t=c[i]-c[i-1];
        if(m-t*(i-j)>=0)
        {
            ans++;
        }
        else
        {
            break;
        }
        m-=t*(i-j);

    }

    mx=max(ans,mx);
}

cout<<mx;
return 0;
}
