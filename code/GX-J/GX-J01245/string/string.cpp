#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,a[1000005],ans=0,m=0;
string b;
cin>>n;
for(long long i=1;i<=n;i++)
{
    cin>>a[i]>>b[i];
    if(b[i]==b[1])
    {
        m++;
    }
}
if(m==n){
    cout<<0;
    return 0;
}m=0;
for(long long i=1;i<=n/2;i++)
{
    if(a[i]==a[n-i+1]&&b[i]==b[n-i+1])
    {
        m++;
    }
}
if(m==n/2){
    cout<<0;return 0;
    }
for(long long i=1;i<=n;i++)
{

    if(a[i]%2==0)
    {
        ans+=a[i]/2;
    }
}
cout<<ans;
return 0;
}

