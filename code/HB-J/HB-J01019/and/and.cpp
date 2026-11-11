#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    int a[300100];
    int maxa=-1000;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];maxa=max(a[i],maxa);
    }

    if (m==n-1)
    {
        int ans=a[1];
        for (int i=2;i<n;i++)
            ans&=a[i];
        for (int i=1;i<n;i++)
        {
            int noa=i,nans=a[0];
            for (int j=0;j<n;j++)
            {
                if (j!=noa)
                    nans&=a[j];
            }
            ans=max(ans,nans);
        }
        cout<<ans;
        return 0;
    }
    if (m==n)
    {
        int ans=a[0];
        for (int j=1;j<n;j++)
            {
                    ans&=a[j];
            }
            cout<<ans;
            return 0;
    }
    if(m==1)
    {
        cout<<maxa;
        return 0;
    }
    if(m==2)
    {
        //cout<<"miao";
        int ans=0;
        for (int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(i&j>=ans)
                {
                    //cout<<i<<" "<<j<<endl;
                    ans=(int)a[i]&a[j];
                }
            }
            //ans=max(ans,i&j);
        cout<<ans;
        return 0;
    }
    if(maxa<4)
    {
        int b[4]={0};
        for (int i=0;i<n;i++)
            b[a[i]]++;
        if(b[3]>=m)
        {
            cout<<"3";
            return 0;
        }
        if(b[2]+b[3]>=m)
        {
            cout<<"2";
            return 0;
        }
        if(b[1]+b[3]>=m)
        {
            cout<<"1";
            return 0;
        }
        cout<<"0";
        return 0;
    }
    sort(a,a+n);
    int ans=a[n-1];
    for (int i=1;i<m;i++)
    {
        ans&=a[n-i-1];
    }
    cout<<ans;
    return 0;
}
