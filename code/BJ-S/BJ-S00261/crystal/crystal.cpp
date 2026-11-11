#include<bits/stdc++.h>
using namespace std;

int a[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int maxx=0;
    int nn=0;
    for(int i=n;i>1;i--)
    {
        if(nn==a[i])continue;
        int mm=m;
        int ans=1;
        nn=a[i];
        for(int j=i-1;j>=1;j--)
        {
            if(mm>=a[i]-a[j])
            {
                mm=mm-a[i]+a[j];
                ans++;
            }
            else
            {
                break;
            }
        }
        maxx=max(maxx,ans);
    }
    cout<<maxx;
    return 0;
}
