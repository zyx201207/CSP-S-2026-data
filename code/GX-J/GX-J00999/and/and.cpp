#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int n,m;
long long f[200010],a[200010];
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=200010;i++)
      f[i]=1;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      int t=a[i]/2,num=a[i]%2,sum=10;
      while(t!=0)
      {
        num=num+t%2*sum;
        sum*=10;
        t/=2;
      }
      a[i]=num;
      cout<<a[i]<<" ";
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=m;j>=1;j--)
        f[j]=max(f[j],f[j-1]&a[i]);
    }
    cout<<f[m];
    return 0;
}
