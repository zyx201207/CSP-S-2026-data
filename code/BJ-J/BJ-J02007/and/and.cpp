#include <iostream>
using namespace std;
int main()
{
    long long n,a[100000],b[100000],m,sum,temp=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1])
            temp++;
    }
    if(temp==n)cout<<"0";
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]%2;
    }
    for(int i=1;i<=m;i++)
    {
        b[i]=b[i]&b[i]+1;
        sum+=b[i];
    }
    cout<<sum;
}
