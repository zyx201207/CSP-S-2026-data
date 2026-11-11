#include<bits/stdc++.h>
using namespace std;
int n,a[200005],tar[200005],dis[200005];
/*void dfs(int num){
	if(num==0) return;
	for(int i=1;i<=n;i++){
		
	}
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			ans=max(ans,a[i]&a[j]);
		}
	}
	/*tar[1]=1;
	for(int i=2;i<=200002;i++){
		tar[i]=tar[i-1]+pow(2,i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=200000;j++){
			if(a[i]>=tar[j]&&a[i]<=tar[j+1]){
				
			}
		}
	}*/
	cout<<ans;
	return 0;
}
