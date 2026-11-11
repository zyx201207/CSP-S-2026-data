#include <bits/stdc++.h>
using namespace std;
int a[20001],c,sum;
int k[1000000];
bool p=0;
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
    int kn=0;
    int ans=0;
    if(m==0)
    {
        for(int i=1;i<=n;i++)
        {
            k[a[i]]++;
            kn=max(kn,a[i]);
        }
        for(int i=1;i<=kn;i++)
        {
            ans=max(ans,k[i]);
        }
        cout<<ans;
        return 0;
    }
    if(n==1)
    {
        cout<<"1";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i+1]&&i!=n)
        {
            p=1;
        }
    }
    if(p==0)
    {
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i+1]-a[i]!=a[i]-a[i-1]&&i!=n)
        {
            p=2;
        }
    }
    if(p!=2)
    {
        int h=a[2]-a[1];
        if(m/h<1)
        {
            cout<<1;
            return 0;
        }
        if(m/h<=n)
        {
            cout<<m/h;
        }
        else
        {
            cout<<n;
        }
        return 0;
    }
    return 0;
}

