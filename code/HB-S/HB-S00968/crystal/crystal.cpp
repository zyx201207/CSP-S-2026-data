#include<bits/stdc++.h>
using namespace std;
int a[500050];
int b[500050];
long long ans=1,cnt=0;
long long ans1=1,ans2=0;
long long m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++)
        b[i]=a[i+1]-a[i];
    for(int i=0;i<n-1;i++)
        if(b[i]==0)
            ans1++;
    for(int i=0;i<n-1;i++)
    {
        i=i+1;
        cnt+=i*b[i-1];
        i=i-1;
        if(cnt<=m)
        {
            ans++;
            if(a[i]==a[i+1])
                ans++;
        }
        if(cnt>=m&&b[i+1]!=0)
            break;
    }
    cnt=0; 
    int x=0;
    for(int i=n-2;i>=0;i--)
    {
        x++;
        cnt+=x*b[i];
        if(cnt<=m)
        {
            ans2++;
            if(a[i]==a[i-1])
                ans2++;
        }
        if(cnt>=m&&b[i-1]!=0)
            break;
    }
    long long maxn=max(ans,ans1);
    maxn=max(maxn,ans2);
    cout<<maxn<<endl;
    return 0;
}