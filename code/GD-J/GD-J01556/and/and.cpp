#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans,k,kk,m,f[16300][16300],num,co; 
//vector<vector<int> >f[16300][16300];
int dfs(int k,int lm) {
	if(lm<0)return -1e9;
	if(k>n)
{

		return -1e9;
	}
	int p,q;
	if(f[k][lm]!=0)p=f[k][lm];
	else p=dfs(k+1,lm);
	if(f[k][lm-1]!=0)q=f[k][lm];
	else q=dfs(k+1,lm-1)+num&a[k];
	
	if(p>q)
	{
		//f[k][lm-1]=q;
		return f[k][lm]=p;
	}
	if(q>p)
	{
		//f[k][lm]=p;
		return f[k][lm-1]=q;	
	}
	if(q==p)
	{
		f[k][lm]=p;
		return f[k][lm-1]=q;
		
}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	//dfs(1,1,pow(2,n)-1,m-1);
	co=num=pow(2,n)-1;
	ans=dfs(1,m);
	cout<<ans/*<<" "<<f[n][0]*/;
	return 0;
 } 
