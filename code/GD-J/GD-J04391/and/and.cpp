#include<bits/stdc++.h>
using namespace std;
long long a[200005]={0},sum=0,ans=0,n;
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(long long x,long long m){
	if(x==m){
		if(sum>=ans){
			ans=sum;
		}
		return;
	}
	
	
	for(long long i=1;i<=n;i++){
		sum=a[i];
		for(long long j=i+1;j<=n;j++){
			sum=sum & a[j];
						
			dfs(x+1,m);			
		}	
		
	}
}
int main(){
	freopen("and.out","r",stdin);
	freopen("and.out","w",stdout);
	long long m;
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	
	dfs(1,m);
	
	cout<<ans;
	
	
	
	return 0;
} 
