#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-1,a[200010],d[2000010];
void dfs(int k,int t){
	if(k<=maxx)return;
	if(t==m){
		maxx=max(maxx,k);
		return;
	}
	if(t==0){
		for(int i=1;i<=n;i++){
			d[i]=1;
			dfs(a[i],t+1);
			d[i]=0;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(d[i]!=1){
				d[i]=1;
				dfs(k&a[i],t+1);
				d[i]=0;
			}
			
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(0,0);
	printf("%d",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
