#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int v,w;
    cin>>v>>w;
    int t;
    int a[10005];
    for(int i=1;i<=v;i++)
   {
   	  cin >> a[i];
   }
   
   for(int j=1;j<=v;j++)
   {
   	   for(int z=1;z<=w;z++)
     {
   	t=a[j]&a[z];
     } 
   }

cout<<t;
return 0;
}
