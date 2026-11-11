#include<bits/stdc++.h>
using namespace std;
int c1,c2,sum1=0,sum2=0,sum3=0,sum4=0;
string s1,s2;
int main()
{
   freopen("travel.in",r,stdin);
   freopen("travel.out",w,stdout);
   cin>>c1>>s1>>c2>>s2;
   if(c1==c2)cout<<1;
   else
   {
       cout<<"0000";
       return 0;
   }
   for(int i=1;i<=3;i++)
   {
        if(int(s1[i])>47&&int(s1[i])<58)sum1+=int(s1[i]);
        if(int(s2[i])>47&&int(s2[i])<58)sum2+=int(s2[i]);

   }
   if(sum1==sum2)cout<<1;
   else
   {
       cout<<"000";
       return 0;
   }
   for(int i=1;i<=3;i++)
   {
        if(int(s1[i])>64&&int(s1[i])<68)sum3++;
        if(int(s2[i])>64&&int(s2[i])<68)sum4++;
   }
   if(sum3==sum4)cout<<1;
   else
   {
        cout<<"00";
        return 0;
   }
   int sum5=0,sum6=0;
   for(int i=1;i<=3;i++)
   {
       if(int(s1[i])>64&&int(s1[i])<70)sum5+=int(s1[i]);
       if(int(s2[i])>64&&int(s2[i])<70)sum6+=int(s2[i]);
   }
   if(sum5+1==sum6||sum5-1==sum6)
   {
       cout<<1;
       return 0;
   }
   else
   {
        cout<<"0";
        return 0;
   }
    return 0;
}
