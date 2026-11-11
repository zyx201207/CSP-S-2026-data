#include <bits/stdc++.h>
using namespace std;
const int k=1e5;
int a[k];
int main()
{
	freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
   	cin>>a[i];
   }
   sort(a,a+n+1);
   for(int i=0;i<n;i++)
   {
   	cout<<a[m];
   	break;
   }
   return 0;
}
