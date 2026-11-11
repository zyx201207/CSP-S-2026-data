#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int M=32;
ll f[N][M],n,m,a[N];
ll ans=0;
vector<int> e[N];
bool v[N][M],pd[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
//	 cout<<a[i]<<":";
	 pd[i]=true;
	 for(int j=0;j<=31;j++)
	 {
	 	if(a[i]&(1<<j))
	 	 v[i][j]=true;
	 	else
	 	 v[i][j]=false;
//	 	cout<<v[i][j]<<"|"<<(1<<j)<<" ";
	 }	
//	 cout<<endl;
	}
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	init();
	for(int j=31;j>=0;j--)
	{
		int pos=0;
		for(int i=1;i<=n;i++)
		 if(pd[i]==true&&v[i][j]==true)
		  pos++;
//		cout<<pos<<endl;
		if(pos>=m)
		{
			ans+=(1<<j);
			for(int i=1;i<=n;i++)
			 if(v[i][j]==false)
			  pd[i]=false; 
		}
	}
	cout<<ans;
	return 0;
}
