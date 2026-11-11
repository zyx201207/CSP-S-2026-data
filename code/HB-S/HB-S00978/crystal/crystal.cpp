#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[500009],s[500009];
int main()
{

    freopen("crystal2.in","r",stdin);
    freopen("4.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=2,mx=0;
    while(r<=n)
    {
        int d=(r-l+1)*(a[r])-(s[r]-s[l-1]);
        if(d<=m)mx=max(mx,r-l+1);
        if(d<=m)r++;
        else if(d>m&&l<r)l++;
        else r++;
    }
    cout<<mx;
//    cerr<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
