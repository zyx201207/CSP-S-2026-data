#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long b[200005],maxx;
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(long long k,long long id){
	if(k>m){
		long long cnt=b[1];
		for(int i=2;i<=m;i++){
			cnt&=b[i];
		}
		maxx=max(maxx,cnt);
		return;
	} 
	for(int i=id;i<=n;i++){
		b[k]=a[i];
		dfs(k+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(pow(n,m)<=100000000){
		dfs(1,1);
		cout<<maxx;
	}else{
		sort(a+1,a+n+1,cmp);
		long long cnt=a[1];
		for(int i=2;i<=m;i++){
			cnt&=a[i];
		}
		cout<<cnt;
	}
	return 0;
}
