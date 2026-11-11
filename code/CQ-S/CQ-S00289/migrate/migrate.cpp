#include<bits/stdc++.h>
using namespace std;
long long sum[5000001];//到某个岛的最短路径长度 
long long a[2000001];
long long ans[2000001];
int c,t;
long long n,d;
void dfs(long long x,long long w){
	if(w>sum[x])return;
	if(w==sum[x])ans[x]++;	
	else {
		sum[x]=min(sum[x],w);
		ans[x]=1;
	}
	for(int j=x+1;n>=j;j++){
		if(abs(a[j]-a[x])<=d){
		dfs(j,w+1);
		}
		else return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;n>=i;i++)cin>>a[i];
		for(int i=1;n>=i;i++)sum[i]=INT_MAX;
		long long h=0;
		for(int i=1;n>=i;i++){	
		for(int j=0;n>=j;j++)sum[j]=INT_MAX;
		dfs(i,0);
		for(int j=1;n>=j;j++)if(ans[j]==2)h++;	
		memset(ans,0,sizeof(ans));
		}
		cout<<h<<endl;
	} 
}
