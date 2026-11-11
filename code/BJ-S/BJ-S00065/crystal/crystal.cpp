#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long b[500050];
long long sa[500050];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    long long sum=0;
    memset(b,0x3f,sizeof(b));
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        b[i-1]=a[i]-a[i-1];

    }
    for(int i=1;i<=n;++i)
    {

        sa[i]=sa[i-1]+b[i];
    }
    int l=1,r=0;
    long long len=0;
    long long ans=0;
    while((l<=r&&r<=n)||(l==1&&r==0))
    {
        if(sum+b[r+1]*(len+1)<=m)
        {
            sum+=b[r+1]*(len+1);
            if(len==0)r=l;
            else r++;
            len++;
            ans=max(ans,len);
        }
        else{
                sum-=sa[r]-sa[l-1];
            l++;
            len--;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}
