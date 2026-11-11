#include<bits/stdc++.h>
using namespace std;
long long n,m,imax=0,a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(long long s,long long x,long long c){
	if(s==m){
		imax=max(imax,x);
		return ;
	}
	else{
		for(int i=c+1;i<=n;i++){
			int k;
			if(s==0) k=a[i];
			else{
				k=x&a[i];
			}
			dfs(s+1,k,i);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==n){
		imax=a[1];
		for(int i=2;i<=n;i++)
			imax&=a[i];
		cout<<imax;
	}
	else{
		dfs(0,0,0);
		cout<<imax;
	}
	return 0;
}
