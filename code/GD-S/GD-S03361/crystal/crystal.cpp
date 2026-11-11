#include<bits/stdc++.h>
using namespace std;
#define fileio
#define IOS
void ___()
{
#ifdef fileio
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
#endif
#ifdef IOS
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    #define endl '\n'
#endif
}
#define ll long long
typedef pair<int,int> pii;
const int _mxn=5e5+10;
int n;
ll m,a[_mxn],s[_mxn];
int main()
{
    ___();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int ans=0;
    for(int k=1;k<=n;k++)
    {
        if(k<n&&a[k]==a[k+1])
            continue;
        int l=1,r=k,res=k;
        while(l<=r)
        {
            int mid=(l+r+1)/2;
            if(a[k]*(k-mid+1)-s[k]+s[mid-1]<=m)
                r=mid-1,res=mid;
            else
                l=mid+1;
        }
        // cout<<res<<" "<<k-res+1<<endl;
        ans=max(ans,k-res+1);
    }
    cout<<ans<<endl;
    return 0;
}
/*
写完时间：15:08

100+68+24+15=207，比去年高一点点

never gonna give you up
never gonna let you down
后面懒得写了

6767676767676767676767676767676767
*/