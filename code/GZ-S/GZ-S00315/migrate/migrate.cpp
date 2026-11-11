//GZ-S00315 冉哲睿 六盘水市第三中学 
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,s,sum,minn,x[2000001];
void dfs(int a,int b,int ans){
	if(a==b){
		if(ans==minn)sum++;
		if(ans<minn){
			minn=ans;
			sum=1;
		}
		return;
	}
	for(int i=a+1;i<=b;i++){
		if(x[i]-x[a]<=d){
			dfs(i,b,ans+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i+3<=n;i++){
			for(int j=i+3;j<=n;j++){
				sum=0;
				minn=INT_MAX;
				dfs(i,j,0);
				if(sum==2)s++;
			}
		}printf("%d\n",s);s=0;
	}
	return 0;
}
