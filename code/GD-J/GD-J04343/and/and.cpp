#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[200009],tt,gg,b[40];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
     for(int i=1;i<=30;i++)
     b[i]=1;
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=30;i++)
    for(int j=1;j<=i;j++)
     b[i]*=2;
sort(a,a+n+1);
tt=a[n];
gg=n-1;
m--;
    for(;m>0&&gg>0;)
   {
   int y=0;
  for(int j=30;j>=1&&b[j]>=a[gg];j--)
       if(a[gg]==b[j])
      y=1;
	   if(y==0)   	
	  {m--;
	  tt=tt&a[gg];
      }
	gg--;
	}	
if(m>0)	
for(int i=1;m>0;)	
{int y=1;
	for(int j=1;j<=30&&b[j]<=a[i];j--)
       if(a[i]==b[j])
      y=0;
      if(y==0)
     {tt=tt&a[i];
     m--;}
  i++;   
}	
	
cout<<tt;	
return 0;
}
