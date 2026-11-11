//贵阳市第十八中学 刘文浩 GZ-J00572
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
bool f[N];
int maxn=0;
int dfs(int x,int y,int sum){
	if(x==n) return 1;
	else{
		sum=y;
		for(int i=1;i<m-1;i++)
			sum=a[i]&&sum;
		maxn=max(maxn,sum);
	}
	for(int i=0;i<n;i++){
		if(f[x]==0){
			f[i]=1;
			a[x]=a[i];
			dfs(x+1,a[i],sum);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<maxn;
	return 0;
}
