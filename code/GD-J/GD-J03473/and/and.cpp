#include <bits/stdc++.h>
using namespace std;
int a[200005],dp[200005];
int n,m,ma=0;
void f(int t,int sum,int t1){
	if(t==m){
		ma=max(sum,ma);
		return;
	}
	for(int i=t1;i<=n;i++){
		if(used[i]==0){
			used[i]=1;
			f(t+1,sum&a[i],i);
			used[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		used[i]=1;
		f(1,a[i],i);
		used[i]=0;
	}
	cout<<ma;
	
	return 0;
}
