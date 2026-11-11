#include<bits/stdc++.h>
using namespace std;
const int N=2<<18;
long long n,m,a[N],b[N],mid,step,ans,mid1,mid2;
long long sous(long long x)
{
    bool f1=false;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        if(f1==false&&a[i]==x){
            f1=true;
            continue;
        }
        b[i]=abs(x-a[i]);
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        if(step+b[i]<=m){
            step+=b[i];
            sum++;
        }
        else break;
        //cout<<b[i]<<" "<<step<<" "<<m<<endl;


    }
    step=0;
    return sum;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n%2!=0)
    {
        mid=a[n/2+1];
        ans=sous(mid);
    }
    else if(n%2==0)
    {
        mid1=a[n/2];
        mid2=a[n/2+1];
        ans=min(sous(mid1),sous(mid2));
    }
    cout<<ans;
    return 0;
}
