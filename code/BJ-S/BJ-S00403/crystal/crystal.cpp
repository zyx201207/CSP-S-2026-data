#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n;
cin>>n;
int ans=0;
for(int i=1;i<=n;i++)
{
    max=max(sort(a+1,a+n+1));
    if(max>a)
    {
        ans=ans+max;
    }
}
cout<<ans;
return 0;
}