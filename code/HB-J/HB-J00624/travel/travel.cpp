#include <bits/stdc++.h>
using namespace std;
string x,y,p,q;
int ans[5]={};
int main()
{
     freopen("travel.in","r",stdin);                                          
     freopen("travel.out","w",stdout);                                        
     cin >>x>>y>>p>>q;
     int flag1=0,flag2=0;
     for (int i=0;i<=1;i++)
     {
	         if (x[i]==p[i]) flag1++;
         	 if (y[i]==q[i]) flag2++;
	}
	if (flag1==2) ans[1]=1;
        if (flag2==2) ans[2]=1;
	if ('A'<=y[2]&&y[2]<='C'&&'A'<=q[2]&&q[2]<='C') ans[3]=1;
	if ((y[2]=='D'||y[2]=='F')&&(q[2]=='D'||q[2]=='F')) {ans[3]=1;ans[4]=1;
}
        if (ans[3]==1&&ans[4]==0&&(y[2]-q[2]==1||q[2]-y[2]==1)) ans[4]=1;
      for (int i=1;i<=4;i++)
        {
	        cout <<ans[i];
         	if (ans[i]==0)
	        {
	                for (int j=i+1;j<=4;j++) cout <<'0';
                        break;
	        }
	}
    return 0;
}
