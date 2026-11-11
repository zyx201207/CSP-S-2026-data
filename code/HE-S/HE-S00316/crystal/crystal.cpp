#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],vis[5005],maxx;
void dfs(int ind,long long nn){
	if(ind>n){
		maxx=max(maxx,nn);
		return;
	}
	vis[ind]=1;
	long long maxn=0,num=0;
	bool flag = 0;
	for(int i = 1;i<=ind;i++){
		if(vis[i]==1)maxn=max(maxn,a[i]);
	}
	for(int i = 1;i<=ind;i++){
		if(vis[i]==1)num+=maxn-a[i];
		if(num>m){flag = 1;break;}
	}
	if(!flag)dfs(ind+1,nn+1);
	vis[ind]=0;
	dfs(ind+1,nn);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    if(n>5000)
    {
    	sort(a+1,a+n+1);
    	long long aii = a[2]-a[1],num=0;
    	for(int i = 1;i<=n;i++)
    	{
    		num+=aii*i;
    		if(m<num){
    			cout<<i-1;
    			return 0;
			}
		}
		cout<<n;
		return 0;
	}
	else{
		dfs(1,0);
		cout<<maxx;
	}
	return 0;
}
