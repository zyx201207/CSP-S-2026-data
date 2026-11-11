#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long a[N],b[N]; 
int n,m;
long long maxn;
void dfs(int x,int step,long long zhi){
	if(step==m){
		maxn=max(maxn,zhi);
		return;
	}
	long long y=zhi;
	for(int i=x+1; i<=n; i++){
		if(step==0)zhi=a[i];
		else zhi=zhi&a[i];
		dfs(i,step+1,zhi);
		zhi=y;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn1=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		maxn1=max(maxn1,a[i]);
	}
	long long cnt=a[1];
	for(int i=1; i<=n; i++)cnt&=a[i];
//	cout<<m;
	if(m==2){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<cnt;
		return 0;
	}if(m==1){
		cout<<maxn1;
		return 0;
	}
	dfs(0,0,0);
	cout<<maxn;
	return 0;
} 
