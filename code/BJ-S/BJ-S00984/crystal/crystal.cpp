#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[500005],b[500005];
long long sum,l,cnt,ans=1;
bool deng=1;
long long d;
void he(int x)
{
    cnt=1;
    sum=0;
    l=0;
    for(int i=x;i>=1;i--)
    {
        l+=b[i];
        sum+=l;
        if(sum>m)
        {
            break;
        }
        cnt++;
    }
    ans=max(ans,cnt);
    return;
}

void dhe()
{
    cnt=1;
    d=b[1];
    sum=0;
    l=0;
    for(int i=1;i<n;i++)
    {
        l+=d;
        sum+=l;
        if(sum>m)
        {
            break;
        }
        cnt++;
    }
    ans=max(ans,cnt);
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    deng=1;
    cin>>n>>m;
    cin>>a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i]-a[i-1];
        b[0]=b[i];
        deng=deng&(b[i]==b[i-1]);
    }
    if(deng==1)
    {
        dhe();
        cout<<ans;
        return 0;
    }
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        b[i]=a[i]-a[i-1];
    }
    //for(int i=1;i<n;i++)
    //{
    //    cout<<b[i]<<" ";
    //}
    for(int i=1;i<n;i++)
    {
        he(i);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
