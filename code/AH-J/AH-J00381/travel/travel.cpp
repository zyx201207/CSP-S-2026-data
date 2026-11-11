#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string ans="";
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   cin>>a>>b>>c>>d;
   if(a!=c)ans="0000";
   else
   {
	   ans+="1";
	   string x="",y="";
	   x+=b[0],x+=b[1];
	   y+=d[0],y+=d[1];
	   if(x!=y)ans+="000";
	   else
	   {
		   ans+="1";
		   if((b[2]=='A' or b[2]=='B' or b[2]=='C') and (d[2]=='D' or d[2]=='F'))ans+="00";
		   else if((d[2]=='A' or d[2]=='B' or d[2]=='C') and (b[2]=='D' or b[2]=='F'))ans+="00";
		   else
		   {
			   ans+="1";
			   if((b[2]=='A' and d[2]=='B') or (b[2]=='B' and d[2]=='C') or (b[2]=='D' and d[2]=='F'))ans+="1";
			   else if((d[2]=='A' and b[2]=='B') or (d[2]=='B' and b[2]=='C') or (d[2]=='D' and b[2]=='F'))ans+="1";
			   else ans+="0";
		   }
	   }
   }
   cout<<ans;
   return 0;
}
