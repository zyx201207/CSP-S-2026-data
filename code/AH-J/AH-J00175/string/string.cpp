#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int n;
struct nu
{
	int x;
	char c;
};
nu a[N];
string st;
int main()
{
   freopen ("string.in","r",stdin);
   freopen ("string.out","w",stdout);
   cin>>n;
   long long cmp=0;
   for(int i=1;i<=n;i++)
   {
   scanf("%d %c",&a[i].x,&a[i].c);
   cmp+=a[i].x; 
   }
   if(n==2 and a[1].x==a[2].x)cout<<cmp/2;
   else cout<<cmp/2-1;
    return 0;
  }

