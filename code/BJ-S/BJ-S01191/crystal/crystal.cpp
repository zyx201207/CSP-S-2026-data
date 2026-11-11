#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
long long n,m;
long long a[500010];
long long diff[500010],sd[500010];
map<long long,int>cnt;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++)
    {
        diff[i]=a[i+1]-a[i];
        sd[i]=sd[i-1]+diff[i];
    }
    int ans=1;
    int l=1;
    for(int r=1;r<=n;r++)
    {
        if(m>=0)
        {
            ans=max(ans,r-l+1);
            //cout<<r<<' '<<l<<endl;
        }
        else
        {
            m+=(sd[r]-sd[l-1]);
            l++;
        }
        m-=(r-l+1)*diff[r];
    }
    cout<<ans;
    return 0;
}
