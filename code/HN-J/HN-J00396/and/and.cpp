#include<bits/stdc++.h>
using namespace std;
long long n,m; 
long long a[2004],b[2004];
long long maxx;
bool flag[2004];
void dfs(int l){
	if(l>=m){
		long long p=b[0];
		for(int j=1;j<m;j++){
			p&=b[j];
		}
		if(p>maxx)maxx=p;
		return;
	}
	for(int j=1;j<=n;j++){
		if(!flag[j]){
			b[l]=a[j];
			flag[j]=1;
			dfs(l+1);
			flag[j]=0;
			b[l]=0;
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
	dfs(0);
	cout<<maxx;
	return 0;
}
