#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long n,m,a[1000100],nus[1000100],max1,maxn=-1;
void solve(long long now,long long sum,long long num,long long to)
{
    if(nus[now]>m)
        solve(to-2,0,1,to-1);
    //cout<<"now:"<<now<<";sum:"<<sum<<";num:"<<num<<";to:"<<to<<endl;
    int sum1=sum*2+nus[now];
    //cout<<"sum1:"<<sum1<<endl;
    if(now<=0||to<=0||sum<0)
    {
        //cout<<"error:   now:"<<now<<";sum:"<<sum<<";num:"<<num<<";to:"<<to<<endl;
        cout<<maxn;
        return;
    }

    else if(sum1>m)
        solve(to-2,0,1,to-1);
    else if(sum1==m)
        cout << num+1;
    else
    {
        maxn=max(maxn,num);
        solve(now-1,sum1,num+1,to);
    }
    return;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n-1;i++)
    {
        nus[i]=a[i+1]-a[i];
        //cout<<"nus["<<i<<"]="<<nus[i]<<endl;
    }
    solve(n-1,0,1,n);
    return 0;
}
