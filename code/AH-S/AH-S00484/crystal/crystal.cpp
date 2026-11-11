#include<bits/stdc++.h>
using namespace std;
const int MAXN=600000;
const int inf=1e9;
//priority_queue <int,vector<int>,greater<int>> q;
int m,n;
int a[MAXN];
int s[MAXN];
int ans;
int cheak(int mid)
{
    int tmp=0;
    for(int i=1;i<mid;i++)
    {
        int added=s[mid]-s[i];
        tmp+=added;
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal2.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    s[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+(a[i]-a[i-1]);
    }
    sort(a+1,a+1+n);
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int num=cheak(mid);
        if(num==m)
        {
            ans=mid;
            break;
        }
        else if(num>m) r=mid-1;
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
