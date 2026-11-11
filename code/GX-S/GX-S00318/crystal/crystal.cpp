#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int  x,sum,k=m;
    int a1=0,ans=0;
    int y=0,ll=0,t=0;
    k=m;
    /*for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            y++;
        }
        else
        {
            if(y>ll)
            {
                t=i-ll;
            }
            ll=max(ll,y);
            y=0;
        }
    }
    if(ll==0)
    {
        x=n/2+1;
    }
    else
    {
        x=t-1;
        cout<<"ll="<<ll<<endl;
    }
    cout<<"x="<<x<<endl;
    for(int i=x;i>0;i--)
    {
        sum=a[x]-a[i];
        if(k>=sum)
        {
            k-=sum;
            a[i]=a[x];
            a1++;
        }
        else
        {
            break;
        }
    }
    cout<<a1;*/
    for(int i=n;i>0;i--)
    {
        a1=1;
        for(int j=i;j>0;j--)
        {
            sum=a[i]-a[j];
            if(k-sum>=0)
            {
                k-=sum;
                a1++;
            }
            else
            {
                break;
            }
        }
        ans=max(a1,ans);
    }
    cout<<ans;
    return 0;
}
