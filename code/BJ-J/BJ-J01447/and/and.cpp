#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    else if(n==m)
    {
        long long ans;
        for(int i=2;i<=n;i++)
        {
            ans=ans|a[i];
        }
    }
    else if(m==2)
    {
        long bi=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]|a[j]>bi){
                    bi=int(a[i]|a[j]);
                }
            }
        }
        cout<<bi;
    }
    else if(m=n-1)
    {
        sort(a+1,a+n+1);
        long long ans;
        for(int i=3;i<=n;i++)
        {
            ans=ans|a[i];
        }
    }
}

