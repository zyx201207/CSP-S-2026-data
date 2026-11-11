#include <bits/stdc++.h>
using namespace std;
int a[500005];
int sum[300005];
int a1[500005];
int an[500005];
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>a[i];

sum[a[n]]++;
for(int i=1;i<n;i++)
{
int top=0;
memset(an,0,sizeof(an));
for(int l=i;l<=n;l++)
{
a1[++top]=a[l];
if(an[a[l]]>0)
{
top--;
while(a1[top]!=a[l])
{
an[a1[top]]=0;
top--;
}
}
else
an[a[l]]=1;
}
for(int i=1;i<=top;i++)
sum[a1[i]]++;

}
for(int i=1;i<=m;i++)
cout<<sum[i]<<" ";


   return 0;
}
