#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],ans=1;
bool f;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    f=true;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>1&&a[i]-a[i-1]!=a[1]-a[0])
        {
            f=false;
        }
    }
    if(f==true)
    {
        ll z=a[1]-a[0],x=z;
        while(m)
        {
            if(m-z<0)
            {
                break;
            }
            ans++;
            m-=z;
            z+=x;
        }
        cout<<ans;
        return 0;
    }
    sort(a,a+n);
    for(ll i=1;i<n;i++)
    {
        ll mm=m,z=0;
        for(ll j=i;j>=0;j--)
        {
            mm-=(a[i]-a[j]);
            if(mm>=0)
            {
                z++;
            }
            else
            {
                break;
            }
        }
        ans=max(ans,z);
    }
    cout<<ans;
    return 0;
}
//#ℹi年从了u的俄《不i他三/三他的从++。和》
//#的俄法i年俄 了了 了哦年个 了哦年个
//u三ℹ年个 年阿名俄三平阿从俄 三他的；
//ℹ年他 名阿ℹ年（）
//『
//  法人俄俄哦平俄年（“。ℹ年”，“人”，三他的ℹ年）；
//  法人俄俄哦平俄年（"。哦u他，“为”，三他的哦u他）；
//  人俄他u人年 0；
//』
