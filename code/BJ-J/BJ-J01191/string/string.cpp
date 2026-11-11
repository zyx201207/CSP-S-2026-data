#include<bits/stdc++.h>
using namespace std;
int a[100005],sum;
char s[10005],new_[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i]>>s[i];
}
int sum=0;
for(int i=1;i<=n;i++)
{

    sum+=a[i];
}
for(int i=1;i<=sum;i++)
{

if(a[i]==1){
new_[i]=s[i];
}
if(a[i]==2)
{
    new_[i]=new_[i+1]=s[i];
}

}
for(int i=1;i<=sum;i++)
    for(int j=sum;j>=1;j--)
{

    if(new_[i]!=new_[j])
    {

        sum++;
    }
    cout<<sum;
    return 0;
}
}
