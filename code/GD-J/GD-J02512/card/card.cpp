#include<bits/stdc++.h>
using namespace std;
int a[500005],p[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(ans,0,sizeof(ans));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++){
			if(p[a[j]]){
				for(int k=j-1;k>=i;k--){
					if(a[k]==a[j]){
						break;
					}
					p[a[k]]=0;
				}
			}
			p[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=p[j];
		}
	}//O(n^3+nm) (A:O(n^2(n-m)))
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//6/25 TLE
