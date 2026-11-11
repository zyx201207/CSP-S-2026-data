#include<bits/stdc++.h>
using namespace std;
struct  ppl{
  int pai;
  string hao;
}
ppi hg[5];
int main()
{
    freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);
     for(int i=1;i<=2;i++)
     {
         cin>>hg[i].pai;
         cin>>hg[i].hao;
     }
     if(hg[1].pai==hg[2].pai)
     cout<<1;
     else
      cout<<0;
    
    string  k,k1;
    k+=hg[1].hao[1];
     k+=hg[1].hao[2];
      k1+=hg[2].hao[1];
       k1+=hg[2].hao[2];
       if(k==k1)
       cout<<1;
       else
       cout<<0;
    

    int flag=0,flag1=0;
    if(hg[1].hao[3]<'e')
    flag=1;
    if(hg[2].hao[3]<'e')
    flag1=1;
    if(flag==flag1)
    cout<<1;
    else cout<<0;
    
    int h=abs(hg[1].hao[3]-hg[2].hao[3]);

    if(h==1)
    cout<<1;
    else
    cout<<0;
    return 0;
}