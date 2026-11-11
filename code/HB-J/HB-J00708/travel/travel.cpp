#include<iostream>
using namespace std;
int main()
{
    int s;
    //freopen("travel.in","r",stdin);
   // freopen("travel.out","w",stdout);
    string c1,c2,m1,m2,s1,s2,n1,n2,n,m;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;else cout<<0;
    n=s1;m=s2;
    n1=s1;m1=s2;
    n2=s1;m2=s2;
   n1.erase(3,3);
   m1.erase(3,3);
   if(n1==n2)cout<<1;else cout<<0;
   n2.erase(0,2);
   m2.erase(0,2);
   if(if(n2=="A"&&m2=="B")||if(n2=="A"&&m2=="C"))//if(n2=="B"&&m2=="A")if(n2=="B"&&m2=="C")if(n2=="C"&&m2=="A")if(n2=="C"&&m2=="B")if(n2=="D"&&m2=="E")if(n2=="E"&&m2=="D")

   return 0;
}
