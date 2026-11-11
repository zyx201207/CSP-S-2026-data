//GZ-J00146 北师大贵阳附中 赵泊宁 
#include<bits/stdc++.h>
using namespace std;
int n,m;
const long long nn=200000;
long long a[nn+5],b[nn+10]={0};
int dfs(long long c,long long d){
	for(int i=1;i<=c;i++){
		b[i]=a[i]&dfs(c,d-1);
	}
	
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(n,m);
	sort(b+1,b+nn+11);
	cout<<b[nn+10]<<endl;
	
	return 0;
}
