#include<bits/stdc++.h>
using namespace std;
int n,sum=-1,m;
int a[200005];
bool v[200005];
void dfs(int i,int u,int num){
	if(u==m){
	sum=max(sum,num);
	return ;
	}
	if(i>n+1)return ;
	for(int j=1;j<=n;j++)if(!v[j]){
		v[j]=true;
		dfs(i+1,u+1,(num==0)?a[j]:num&a[j]);
		v[j]=false;
	}
	dfs(i+1,u,num);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==1){
		int maxn=-1;
		for(int i=1;i<=n;i++)
		maxn=max(maxn,a[i]);
		cout<<maxn<<endl;
		return 0;
	}
	else if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(i!=j)maxn=max(maxn,a[i]&a[j]);
		cout<<maxn<<endl;return 0;
	} 
	else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++)
		sum&=a[i];
		cout<<sum<<endl;return 0;
	}
	else{
		dfs(1,0,0);
		cout<<sum;	
	}
	return 0;
}
