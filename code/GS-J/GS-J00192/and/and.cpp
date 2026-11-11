#include<bits/stdc++.h>
using namespace std;
int m,n,a[200015];
int s[200015], ans;
bool p[200015];
/*void bfs(int step,int ansnow){
	if(step>m){
		ans=max(ans,ansnow);
		return;
	}
	long long x=ansnow;
	for(int i=step;i<=n;i++){
		if(!p[i]){
			x
		}
	}
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
//	scanf("%d",&a[1]);
//	s[1]=a[1];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);		
		s[i]+=s[i-1]&a[i];	
	}	
//	dfs(1,ans);
	if(m==1){
		for(int i=1;i<=n;i++)
		ans=max(ans,a[i]);
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i+m<=n;i++){
		ans=max(ans,s[i+m]|a[i]);
	}
	printf("%d",ans);
	return 0;
}
