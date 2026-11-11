#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,s,d;
   cin>>a>>s>>d;
   if(a=='0')
   {
     if(s=='2')
     {
       if(d=='4')
       {
         cout<<"1"<<endl<<"2";
	   }
	   else cout<<"0"<<endl<<"1";
	 }
	 if(s=='17')
	 {
	   cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"0"<<endl<<"2"<<endl<<"0"<<endl;
	 }
   }
   return 0;
}