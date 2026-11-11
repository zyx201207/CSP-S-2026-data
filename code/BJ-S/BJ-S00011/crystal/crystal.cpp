#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=7005;
int n;
long long m,a[N],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int l=i,r=i;
        int sum=m,cnt=1;
        int disl=a[i]-a[i-1],disr=a[i+1]-a[i];
        while((sum>=disl&&l>1)||(sum>=disr&&r<n))
        {
            if(l==1&&r==n) break;
            if(sum<disr&&l>1)
            {
                l--;
                sum-=disl;
            }
            else if(sum<disl&&r<n)
            {
                r++;
                sum-=disr;
            }
            else if((disl<=disr||r==n)&&l>1)
            {
                l--;
                sum-=disl;
            }
            else if((disl>=disr||l==1)&&r<n)
            {
                r++;
                sum-=disr;
            }
            cnt++;
            disl=a[i]-a[l-1];
            disr=a[r+1]-a[i];
        }
        ans=max(ans,1ll*cnt);
    }
    cout<<ans;
    return 0;
}
