#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],cny,cnb,maxx=-1,b[500005];
//void dfs(int x,long long h,long long i){
//	if(h>m){
//		maxx=max(maxx,i);
//		return ;
//	}
//	dfs(x+1,h+b[x],i++);
//	dfs(x+1,h,i++);
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<n;i++){
//		b[i]=a[i+1]-a[i];
//	}
//	dfs(1,0,1);
//	cout<<maxx;
	for(int i=1;i<=n;i++){
		int j=a[i+1]-a[i];
		if(j==1){
			cnb++;
		}
	}
	if(cnb==n-1){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if((a[i]+a[j])*(j-i+1)/2==m){
					maxx=max(maxx,j-i+1+1);
					break;
				}
			}
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
