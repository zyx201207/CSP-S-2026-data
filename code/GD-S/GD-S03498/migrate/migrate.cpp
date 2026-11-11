#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
ll n,m,p[N],a[N],c,T,r[N];
struct node{
	ll pos;
	ll minn;
};
node f[510][510];
int query1(ll x)
{
	ll qwe=m/x;
	if(qwe<=1)
	 return 0;
	ll wer=(qwe-1)+qwe;
	ll ans=0;
	for(ll i=1;i+wer<=n;i++)
	 ans++;
	return ans;
}
int query2()
{
	for(int i=2;i<=n;i++)
	 if(p[i]<=m)
	 {
	 	f[i-1][i].pos=1;
	 	f[i-1][i].minn=1;
	  }else
	  {
		f[i-1][i].minn=-1;  	
	  }
	ll ans=0;
	for(int k=3;k<=n;k++)
	{
		for(int i=1;i<=n-k+1;i++)
		{
			int j=i+k-1;
			if(abs(a[i]-a[j])<=m)
			{
				f[i][j].minn=1;
				f[i][j].pos=1;
				continue;
			}
			f[i][j].minn=1e9;
			f[i][j].pos=0;
			for(int z=i+1;z<j;z++)
			{
				
				if(f[i][z].minn==-1||f[z][j].minn==-1)
				 continue;
//				cout<<i<<" "<<z<<" "<<j<<endl;
				if(f[i][z].minn+f[z][j].minn==f[i][j].minn)
				 f[i][j].pos+=f[i][z].pos*f[z][j].pos; 
				if(f[i][z].minn+f[z][j].minn<f[i][j].minn)
				 f[i][j].minn=f[i][z].minn+f[z][j].minn,f[i][j].pos=1;
			}
//			cout<<i<<" "<<j<<"|"<<f[i][j].minn<<endl;
			if(f[i][j].minn>=1e9)
			 f[i][j].minn=-1;
			if(f[i][j].pos==2)
			 ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>T;
	for(int o=1;o<=T;o++)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		sort(a+1,a+1+n);
		ll pos=0;
		bool pd=true;
		for(int i=2;i<=n;i++)
		{
		 p[i]=a[i]-a[i-1];
		 if(pos==0)
		  pos=p[i];
		 if(p[i]!=pos)
		  pd=false;
		}
		if(pd==true)
		 cout<<query1(pos)<<endl;
		else
		 cout<<query2()<<endl;;
	}
	return 0;
}
/*
0 3
6 3
0 1 2 3 4 7
8 3
0 1 2 4 8 10 11 13
1 3
0


*/
