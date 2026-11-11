#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==m)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==1)
        cout<<a[n];
    else if(m==2)
    {
        int maxx=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int khy=a[i]&a[j];
                maxx=max(maxx,khy);
            }
        }
        cout<<maxx;
    }
    else if(n>2000)
    {
        sort(a+1,a+1+n);
        int a=0,b=0,c=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1) a++;
            if(a[i]==2) b++;
            if(a[i]==3) c++;
            if(a>=m or b>=m or c>=m);
            cout<<3;
            else if(a+c>=m)
            cout<<1;
            else if(b+c>=m)
                cout<<2;
            else cout<<0;
        }
    }
    return 0;
}