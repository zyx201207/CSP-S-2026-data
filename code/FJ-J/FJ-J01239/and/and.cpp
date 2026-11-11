#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200005],dp[200005],f[4005][4005],ans;
bool d[40005][40005];
void dfs(int x,int ml,long long jg){
	if(ml==m){
		ans=max(ans,jg);
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,ml+1,(jg&a[i]));
	}
} 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];dp[i]=a[i];
	}
	if(n*m<500*500){
		for(int i=1;i<=n;i++){
			dfs(i,1,a[i]);
		}	
		cout<<ans;
	}
	else {
		sort(a+1,a+1+n,cmp);
		long long s=a[1];
		for(int i=2;i<=m;i++){
			s=(s&a[i]);
		}ans=max(ans,s);
		s=a[2];
		for(int i=3;i<=m+1;i++){
			s=(s&a[i]);
		}ans=max(ans,s);
		s=a[3];
		for(int i=4;i<=m+2;i++){
			s=(s&a[i]);
		}ans=max(ans,s);
		s=a[4];
		for(int i=5;i<=m+3;i++){
			s=(s&a[i]);
		}ans=max(ans,s);
		s=a[5];
		for(int i=6;i<=m+4;i++){
			s=(s&a[i]);
		}ans=max(ans,s);
		cout<<ans;
	}
//	else if(n*m<=4004*4004){//
//		for(int i=2;i<=m;i++){
//			for(int j=1;j<=n;j++){
//				if(!d[i-1][j]){
//					dp[i]=max(dp[i],dp[i-1]&a[j]);
//					
//				}d[i][j]=1;
//			}
//		}
//		cout<<dp[m];
//	}
//	else {
//		for(int i=2;i<=m;i++){
//			for(int j=1;j<=n;j++){
//				dp[i]=max(dp[i],(dp[j-1]&a[j]));
//			}
//		}
//		cout<<dp[m];
//	}

}
