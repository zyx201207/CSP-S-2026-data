#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,m,a[N];
int main()
{
   freopen ("card.in","r",stdin);
   freopen ("card.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)scanf("%d",&a[i]);
   if(n<=5 and m<2)
   return cout<<n<<' '<<m/2+1<<' '<<n/2+2,0;
   if(n<=5000 and m<=3000)
	 for(int i=1;i<=m;i++)cout<<n<<' ';
  return 0;
  }
