#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   string r,x,rid,xid,a;
   cin>>r>>rid>>x>>xid;
   int ry=(r[0]-'0')*10+(r[1]-'0'),xy=(x[0]-'0')*10+(x[1]-'0');
   int rz=(rid[0]-'0')*10+(rid[1]-'0'),xz=(xid[0]-'0')*10+(xid[1]-'0');
   for(int i=0;i<=3;i++)
        a[i]='0';
   if(xy==ry)
   {
       a[0]='1';
       if(rz==xz)
       {
         a[1]='1';
         if((rid[2]<'D'&&xid[2]<'D')||(rid[2]>='D'&&xid[2]>='D'))
         {
           a[2]='1';
           if((rid[2]-xid[2]==1)||(xid[2]-rid[2]==1))
             a[3]='1';
         }
         else
         {
            for(int i=0;i<=3;i++)
            cout<<a[i];
            return 0;
         }
       }
       else
       {
         for(int i=0;i<=3;i++)
         cout<<a[i];
         return 0;
       }
   }
   else
   {
      for(int i=0;i<=3;i++)
      cout<<a[i];
      return 0;
   }
    for(int i=0;i<=3;i++)
     cout<<a[i];
    return 0;
}
