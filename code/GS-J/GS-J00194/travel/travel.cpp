#include<bits/stdc++.h>
using namespace std;
int cx[2],hs[2],zwh[2];
string cr,cr1;
bool cxn,hsn,tc,xl;
bool pd(int x,int y)
{
if(x==1&&y==2) return 1;
if(x==2&&y==1) return 1;
if(x==2&&y==3) return 1;
if(x==3&&y==2) return 1;
if(x==1&&y==3) return 1;
if(x==3&&y==1) return 1;
if(x==4&&y==5) return 1;
if(x==5&&y==4) return 1;
return 0;
}
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>cx[0]>>cr>>cx[1]>>cr1;
hs[0]=(cr[0]-'0')*10+(cr[1]-'0');
zwh[0]=cr[2]-'A'+1;
hs[1]=(cr1[0]-'0')*10+(cr1[1]-'0');
zwh[1]=cr1[2]-'A'+1;
if(cx[0]==cx[1])
{
cxn=1;if(hs[0]==hs[1])
{
hsn=1;if(pd(zwh[0],zwh[1]))
{
tc=1;if(abs(zwh[0]-zwh[1])==1)
xl=1;
}
}
}
cout<<cxn<<hsn<<tc<<xl;
return 0;
}
