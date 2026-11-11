#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200005],cnt;
/*void dfs(long long x,int y,long long z){
	if(z>m){
		cnt=max(cnt,y);
		return;
	}
	for(long long i=x+1;i<=n-(m-z);i++){
		dfs(i,(y&a[i]),z+1);
	}
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	//dfs(1,a[1],1);
	sort(a+1,a+n+1);
	cout<<a[n-m+1]<<endl;
	//cout<<cnt<<endl;
	return 0;
}
