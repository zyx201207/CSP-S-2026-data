#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005],c[200005];
int w[200005];
int g=0;
int dfs(int gs,int maxs){
	if(gs==m)
	{
		int t=c[1];
		for(int i=1;i<=m;i++)
		{
			t=t&c[i];
		}
		if(t>=maxs) maxs=t;
		return maxs;
	 } 
	 for(int i=1;i<=n;i++)
	 {
	 	if(b[i]!=1)
	 	{
	 		b[i]=1;
	 		c[++gs]=a[i];
	 		w[g++]=dfs(gs,maxs);
	 		c[gs]=0;
	 		gs--;
	 		b[i]=0;
		 }
	 }
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	dfs(0,0);
	int d=0;
	for(int i=0;i<g-1;i++)
	{
		if(w[i]>=d) d=w[i];
	}
	cout<<d;
	return 0;
} 
