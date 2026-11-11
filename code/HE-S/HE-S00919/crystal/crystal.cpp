#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll m=0,n=0,ans=0,cnt=0,vnt=0;
    cin>>n>>m;
    ll a[n]={0};
    const ll tempm=m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(ll i=1;i<n;i++)
    {
        ll task=a[i];
        for(ll j=i;;j--)
        {
            if(a[j]==task)
                vnt++;
            else
                vnt=0;break;
        }
        if(task==a[i+1] && i+1<n)
            continue;
        for(ll j=0;j<i;j++)
        {
            if(task-a[j]<=m && m>0)
            {
                cnt++;
                m=m-task+a[j];
            }
        }
        ans=max(ans,cnt+vnt);
        m=tempm;
        vnt=0;
        cnt=0;
    }
    cout<<ans;
    return 0;
}
