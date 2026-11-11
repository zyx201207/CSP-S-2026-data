include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long  a[20010][31]={};
long long  n,m,s[20010]={},x;
cin>>n>>m;

for(long long i=0;i<n;i++)
{
    cin>>x;
    long long t=0;
    while(x)
    {
        a[i][t++]=x%2;
        x/=2;
    }
}


long long vis[20010]={},ans=0;
for(long long i=0;i<n;i++)
{
    vis[i]=1;
}
for(long long i=30;i>=0;i--)
{
  long long c=0;
for(long long j=0;j<n;j++)
    {
      if(a[j][i]==1&&vis[j]==1)
        {
            c++;
            vis[j]++;
        }

    }
    if(c>=m)
    {
    for(long long j=0;j<n;j++)
    {
        vis[j]--;
    }
    ans+=pow(2,i);

    }
    else
    {
        for(long long j=0;j<n;j++)
        {
        vis[j]=1;
        }
    }
}
cout<<ans;

    return 0;
   fclose(stdin);
fclose(stdout);
}
