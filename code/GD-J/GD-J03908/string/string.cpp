#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],L,z[N],y[N],qzh[27][N],ans=0; 
struct node{
	ll x,yuan;
	char c;
};
node f[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	ll last=0;
	for(int i=1;i<=n;i++)
	{
	 cin>>f[i].x>>f[i].c;
	 f[i].yuan=i;
	 z[i]=last+1;
	 y[i]=z[i]+f[i].x-1;
	 last=y[i];
//	 cout<<z[i]<<"|"<<y[i]<<endl;
	 for(int j=0;j<=25;j++)
	 {
	  qzh[j][i]+=qzh[j][i-1];
	  if(j==f[i].c-'a')
	   qzh[j][i]+=f[i].x;
	 }
	 qzh[26][i]=qzh[26][i-1]+f[i].x;
	}
	L=last;
//	cout<<L<<endl;
	for(int i=1;i<=n;i++)
	{
		ll pos1=L+1-y[i],pos2=L+1-z[i];
		ll zl=upper_bound(z+1,z+1+n,pos2)-z;
		zl--;
		ll yl=lower_bound(y+1,y+1+n,pos1)-y;
//		cout<<"pos1:"<<pos1<<" pos2:"<<pos2<<" "<<z[zl]<<" "<<y[yl]<<endl;
		if(zl==yl)
		{
			if(f[zl].c!=f[i].c)
			 ans+=f[i].x;
			continue;
		}
//		cout<<ans<<"|";  
		if(f[zl].c!=f[i].c)
			ans+=(pos2-z[zl]+1);
//		cout<<ans<<"|";  
		if(f[yl].c!=f[i].c)
			ans+=(y[yl]-pos1+1);
		if(zl-1>=yl+1)
		 ans+=qzh[26][zl-1]-qzh[26][yl]-(qzh[f[i].c-'a'][zl-1]-qzh[f[i].c-'a'][yl]);
//		cout<<ans<<endl;
	}
	cout<<ans/2;
	return 0;
}
/*
5
2 a
24 b
32 c
12 b
30 a
*/
