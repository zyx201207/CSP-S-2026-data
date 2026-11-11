#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],ans=0,c=0;
char b[1000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        ans+=a[i];
        if(b[i]==b[i-1])
        {
            c++;
        }
    }
    if(ans%2==0)
    {
        cout<<ans/2;
        return 0;
    }
        cout<<"0";
        return 0;
}
