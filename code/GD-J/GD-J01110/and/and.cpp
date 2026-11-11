#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx;
bool cx[200005];
void dfs(long long k,long long s)
{
	if(k>m){mx=max(mx,s);return ;}
	for(int i=1;i<=n;i++)
		if(!cx[i])
		{
			if(s==0) cx[i]=1,dfs(k+1,a[i]),cx[i]=0;
			else cx[i]=1,dfs(k+1,(s&a[i])),cx[i]=0;
		}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);//¸Ä 
	freopen("and.out","w",stdout);//¸Ä 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0);
	cout<<mx;
	
	return 0;	
} 
