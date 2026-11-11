#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int p[200005];
long long maxx=0;
int n,m;
void dfs(int k){
	if(k==m+1){
		long long sum=a[p[1]];
		for(int i=2;i<=m;i++){
			sum&=a[p[i]];
			if(sum==0){
				break;
			}
		}
		if(sum>maxx){
			maxx=sum;
		}
	}else{
		for(int i=p[k-1]+1;i<=n;i++){
			p[k]=i;
			dfs(k+1);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long h=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>h){
			h=a[i];
		}
	}
	if(m==1){
		cout<<h;
		return 0;
	}
	if(n==m){
		long long u=a[1];
		for(int i=2;i<=n;i++){
			u&=a[i];
		}
		cout<<u;
		return 0;
	}
	dfs(1);
	cout<<maxx;
	return 0;
}
