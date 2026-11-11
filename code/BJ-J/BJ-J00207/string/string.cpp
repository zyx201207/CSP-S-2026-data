#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll a[N],ca[N];
char b[N],cb[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        ca[n-i+1]=a[i];
        cb[n-i+1]=b[i];
    }
    ll sum=0;
    for(int i=1,j=1;i<=n || j<=n;)
    {
        //cout<<i<<" "<<a[i]<<" "<<b[i]<<"  "<<j<<" "<<ca[j]<<" "<<cb[j]<<endl;
        if(a[i]>ca[j])
        {
            if(b[i]!=cb[j]) sum+=ca[j];
            a[i]-=ca[j];
            ca[j]=0;
        }
        else if(a[i]<ca[j])
        {
            if(b[i]!=cb[j]) sum+=a[i];
            ca[j]-=a[i];
            a[i]=0;
        }
        else if(a[i]==ca[j])
        {
            if(b[i]!=cb[j]) sum+=a[i];
            ca[j]=0;
            a[i]=0;
        }
        if(!a[i]) i++;
        if(!ca[j]) j++;
        //cout<<i<<" "<<a[i]<<"  "<<j<<" "<<ca[j]<<endl;
        //cout<<sum<<endl;
    }
    sum/=2;
    cout<<sum<<endl;
    return 0;
}
