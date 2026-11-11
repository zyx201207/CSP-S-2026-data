#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum,num;
long long dk;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    //cout<<n;
    vector<long long> shu(n,0);
    char mu[200010];
    for(int i=1;i<=n;i++)cin>>shu[i]>>mu[i];
    if(n%2!=0)n++;
    //for(int i=1;i<=n;i++)cout<<shu[i]<<" "<<mu[i]<<"\n";
    for(int i=1,j=n;i<=n/2;i++,j--)
    {
        if(sum<0)shu[i]+=abs(sum);
        else shu[j]+=sum;
        //if(i>1 && mu[i-1]!=mu[j])dk+=sum;
        if(mu[i]!=mu[j])
        {
            sum=shu[i]-shu[j];
            num=min(shu[i],shu[j]);
            dk+=num;
        }
        //cout<<i<<" "<<sum<<" "<<num<<" "<<dk<<"\n";
    }
    cout<<dk;
    return 0;
}
