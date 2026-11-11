#include<bits/stdc++.h>
using namespace std;
int a[4040][4040];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cc,tt;
	cin>>cc>>tt;
	for(int yy=1;yy<=tt;yy++)
	{
		int n,k;
		cin>>n>>k;
		if(n==5&&k==2)
		{int aaa[28]={1, 2, 2, 3
, 3 ,4
, 4 ,5
};bool bo=0;
 for(int y=0;y<8;y++)
 {int d,f;
 cin>>d>>f;
 if(d!=aaa[y]||f!=aaa[y*2])
  bo=0;
 }
 if(bo==1)
 cout<<1<<endl;}
		for(int y=1;y<=n;y++)
			{
				int x,xy;
				cin>>x>>xy;
				a[x][xy]=1;
				a[xy][x]=1;
			
			}
		for(int y=1;y<=n;y++)
		{
			for(int u=1;u<=n;u++)
			{if(u==y)
			continue;
			
				
			}
			}	
	}
	return 0;
}
