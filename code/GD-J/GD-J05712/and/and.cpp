#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool chosed[200005]={0};
int ii[200005],iii=1;
int dfs(int sum,int i){
	if(sum==m){
		int ans=a[ii[1]];
		for(int k=2;k<iii;k++){
			ans&=a[ii[k]];
		}
		return ans;
	}
	int mx=0;
	int x;
	for(int k=i;k<=n;k++){
		if(!chosed[k]){
			chosed[k]=1;
			ii[iii++]=k;
			x=dfs(sum+1,k+1);
			if(x>mx)	mx=x;
			chosed[k]=0;
			ii[--iii]=0;
		}
	}
	return mx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=dfs(0,1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
