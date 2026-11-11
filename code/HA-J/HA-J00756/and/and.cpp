#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,a[200005],b[2005],maxx;
void dfs(long long c,long long i){
	if(c>m){
		sum=a[b[1]];
		for(int j=2;j<=m;j++){
			sum&=a[b[j]];
		}
		maxx=max(maxx,sum);
	}
	else{
		long long x=c;
		for(b[c]=i+1;b[c]<=n;b[c]++){
			dfs(c+1,b[x]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		if(m==n-1){
			for(int i=1;i<=n;i++){
				sum&=a[i];
				maxx=max(sum,maxx);
				sum&=a[i];
			}
			cout<<maxx;
			return 0;
		}
	}
	else{
		if(m==n){
			sum=a[1];
			for(int i=2;i<=n;i++){
				sum&=a[i];
			}
			cout<<sum;
			return 0;	
		}
		dfs(1,0);
		cout<<maxx;
	}
	return 0;
}
