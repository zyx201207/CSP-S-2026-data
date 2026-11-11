#include<bits/stdc++.h>
using namespace std;
int n,cs,cd,f=0,sy;
long long ans,zh,yb;
string s;
struct node
{
	int gs;
	char zm;
 } a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i].gs>>a[i].zm;
	int wz=n;
	sy=a[n].gs;
	for(int i=1;i<=n;i++)
	{
	  int hs=a[i].gs;
	  if(i==wz)
	  {
	  	f=1;
	  	break;
	  }
	  else
	  while(hs)
	  {
	  	if(sy>hs)
	  	{
		  if(a[i].zm!=a[wz].zm)	
		 ans+=hs;
	  	 sy=sy-hs;
	  	 hs=0;
		}
		else
		{
		if(a[i].zm!=a[wz].zm)
		ans+=sy;	
		hs-=sy;
		wz--;
		sy=a[wz].gs;
		}
	  }	
	}
	if(f==1)
	 cout<<ans;
	 else
	 cout<<ans/2;
	return 0;
}
