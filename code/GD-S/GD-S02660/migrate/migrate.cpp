#include<bits/stdc++.h>
using namespace std;
long long x[2000010],d;
int n;
int lforsolve12,disforsolve12[10][10],ansforsolve12[10][10];
void dfs1forsolve12(int step,int sum,int last){
	if(step==n+1)
		return;
	disforsolve12[lforsolve12][step]=(disforsolve12[lforsolve12][step]==0?sum:min(disforsolve12[lforsolve12][step],sum));
	if(x[step]-x[last]<=d)
		dfs1forsolve12(step+1,sum,last);
	else{
		dfs1forsolve12(step+1,sum+1,step);
		cerr<<step<<' '<<sum<<' '<<last<<'\n';
	}
	return;
}
void dfs2forsolve12(int step,int sum,int last){
	if(step==n+1)
		return;
	if(sum==disforsolve12[lforsolve12][step])
		ansforsolve12[lforsolve12][step]++;
	if(x[step]-x[last]<=d)
		dfs2forsolve12(step+1,sum,last);
	dfs2forsolve12(step+1,sum+1,step);
	return;
}
void solve12(){
	int ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",x+i);
	for(int i=1;i<n;i++)
		lforsolve12=i,dfs1forsolve12(i+1,1,i);
	for(int i=1;i<n;i++)
		lforsolve12=i,dfs2forsolve12(i+1,1,i);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(ansforsolve12[i][j]==2)
				ans++;
			cerr<<disforsolve12[i][j]<<' ';
		}
		cerr<<'\n'; 
	}
	printf("%d\n",ans);
}
void solve36(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	scanf("%d%d",&c,&t);
	if(1<=c&&c<=2||true)
		while(t--)
			solve12();
	return 0;
}
