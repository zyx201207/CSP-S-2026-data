#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool t[200005];
int dfs(int k,int p){
	int ans;
	if(k>=m-1){
		ans=2147483647;
		for(int i=0;i<n;i++){
			if(t[i]) ans&=a[i];
		}
		return ans;
	}
	for(int i=p;i<n;i++){
		t[i]=1;
		ans=max(ans,dfs(k+1,p+1));
		t[i]=0;
		ans=max(ans,dfs(k,p+1));
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	printf("%d",dfs(0,0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
