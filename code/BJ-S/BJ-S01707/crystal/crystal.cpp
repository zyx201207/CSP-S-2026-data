#include<bits/stdc++.h>
using namespace std;
int a[500005];
int c[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxx=0;
    for(int i=1;i<=n;i++)   cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        memset(c,0,sizeof(c));
        for(int j=1;j<i;j++)  c[j]+=a[i]-a[j];
        int ans=0,sum=m;
        for(int j=i-1;j>=1;j--)
        {
            if(c[j]<=sum){
                sum-=c[j];
                ans++;
            }
            else{
                break;
            }
        }
        maxx=max(maxx,ans+1);
    }
    cout<<maxx;
    return 0;
}
