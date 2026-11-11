#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   int v;
   cin>>v;
   char a[10005];
   int s=0;
   for(int i=1;i<=v ;i++)
   {
   	cin>>a[i];
   }
   for(int i=1;i<=v ;i++)
   {
   	int w=a[i]%10;
   }
   
   if(a[1]%a[i-1])
   {
   	s++;
   }
   else if(a[i]!=a[i-1])
{
   	s++;
   }
   cout<<s;
   return 0;
}

