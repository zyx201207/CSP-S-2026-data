#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
int n;
cin>>n;
int ans=0;
for(int i=1;i<=n;i++)
{
for(int j=i+1;j<=n;j++)
{
if(n!=0)
{
ans=i*j;
}
}
}
cout<<ans<<endl;
return 0;