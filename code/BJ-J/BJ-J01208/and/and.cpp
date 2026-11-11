
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxi=-1e18;
ll n,m,a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==2)
    {
        for(ll i=1;i<n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                maxi=max(maxi,a[i]&a[j]);
            }
        }
    }
    else if(m==3)
    {
        for(ll i=1;i<=n-2;i++)
        {
            for(ll j=i+1;j<=n-1;j++)
            {
                for(ll k=j+1;k<=n;k++)
                {
                    maxi=max(maxi,a[i]&a[j]&a[k]);
                }
            }
        }
    }
    else if(m==4)
    {
        for(ll i=1;i<=n-3;i++)
        {
            for(ll j=i+1;j<=n-2;j++)
            {
                for(ll k=j+1;k<=n-1;k++)
                {
                    for(ll l=k+1;l<=n;l++)
                    {
                        maxi=max(maxi,a[i]&a[j]&a[k]&a[l]);
                    }
                }
            }
        }
    }
    else if(m==5)
    {
        for(ll i=1;i<=n-4;i++)
        {
            for(ll j=i+1;j<=n-3;j++)
            {
                for(ll k=j+1;k<=n-2;k++)
                {
                    for(ll l=k+1;l<=n-1;l++)
                    {
                        for(ll o=l+1;o<=n;o++)
                        {
                            maxi=max(maxi,a[i]&a[j]&a[k]&a[l]&a[o]);
                        }
                    }
                }
            }
        }
    }
    else if(m==6)
    {
        for(ll i=1;i<=n-5;i++)
        {
            for(ll j=i+1;j<=n-4;j++)
            {
                for(ll k=j+1;k<=n-3;k++)
                {
                    for(ll l=k+1;l<=n-2;l++)
                    {
                        for(ll o=l+1;o<=n-1;o++)
                        {
                            for(ll p=o+1;p<=n;p++)
                            {
                                maxi=max(maxi,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
                            }
                        }
                    }
                }
            }
        }
    }
    else if(m==7)
    {
        for(ll i=1;i<=n-6;i++)
        {
            for(ll j=i+1;j<=n-5;j++)
            {
                for(ll k=j+1;k<=n-4;k++)
                {
                    for(ll l=k+1;l<=n-3;l++)
                    {
                        for(ll o=l+1;o<=n-2;o++)
                        {
                            for(ll p=o+1;p<=n-1;p++)
                            {
                                for(ll q=p+1;q<=n;q++)maxi=max(maxi,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]);
                            }
                        }
                    }
                }
            }
        }
    }
    else if(m==8)
    {
        for(ll i=1;i<=n-7;i++)
        {
            for(ll j=i+1;j<=n-6;j++)
            {
                for(ll k=j+1;k<=n-5;k++)
                {
                    for(ll l=k+1;l<=n-4;l++)
                    {
                        for(ll o=l+1;o<=n-3;o++)
                        {
                            for(ll p=o+1;p<=n-2;p++)
                            {
                                for(ll q=p+1;q<=n-1;q++)
                                {
                                    for(ll r=q+1;r<=n;r++)maxi=max(maxi,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(m==9)
    {
        for(ll i=1;i<=n-8;i++)
        {
            for(ll j=i+1;j<=n-7;j++)
            {
                for(ll k=j+1;k<=n-6;k++)
                {
                    for(ll l=k+1;l<=n-5;l++)
                    {
                        for(ll o=l+1;o<=n-4;o++)
                        {
                            for(ll p=o+1;p<=n-3;p++)
                            {
                                for(ll q=p+1;q<=n-2;q++)
                                {
                                    for(ll r=q+1;r<=n-1;r++)
                                    {
                                        for(ll s=r+1;s<=n;s++)maxi=max(maxi,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<maxi;
    return 0;
}

