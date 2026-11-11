#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , a[1000000000] , s =0;
    char b[1000000000] ;
   freopen("string.in" , "r" ,stdin);	
   freopen("string.out" , "w" ,stdout);	
   cin >> n;
   for(int i = 1;i <= n; i++)
   {
   	cin >> a[i] >> b[i];
   	if(b[i] == b[i-1]) a[i] += a[i-1];
   }
   int z = a[1];
   for(int i = 2; i <= n ; i++)
   {
   	s+= a[i];
   }
   if(z < s) cout << z;
   else cout << s;
   return 0;
} 
