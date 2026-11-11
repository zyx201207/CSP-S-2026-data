#include<bits/stdc++.h>
using namespace std;
int k=1,c,p,z,l,bic1,bic2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,rc,rz,xc,xz,zc;
    cin>>s;
    for(int i=0;i<13;i++)
    {
   //     if(s[i]==' ')
   //     {
    //        for(int j=0;j<zc.size();j++)
   //         {
    //            if(k==1) rc[j]+=zc[j];
    //            if(k==2) rz[j]+=zc[j];
    //            if(k==3) xc[j]+=zc[j];
    //        }
         //   k++;
         // //  zc="";
       // }else{
            zc[i]+=s[i];
      //  }
    }

    for(int i=0;i<zc.size();i++)
    {
        xz[i]+=zc[i];
    }
    if(rc[0]=='0')
    {
        if((rc[1]-'0')==(xc[1]-'0'))
        {
            c=1;
        }
    }else{
        if((rc[0]-'0')*10+rc[1]-'0'==(xc[0]-'0')*10+xc[1]-'0')
        {
            c=1;
        }
    }
    return 0;
}
