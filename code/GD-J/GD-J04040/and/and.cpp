#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int a[MAX],n,m,ans=-1;
bool used[MAX];
int as[MAX];
void slove(int dep){
	if(dep>m){
		int t=as[1];
		for(int i=2;i<=m;i++) t=t&as[i];
		ans=max(ans,t);
	}
	for(int i=0;i<n;i++){
		if(used[i]) continue;
		used[i]=1;
		as[dep]=a[i];
		slove(dep+1);
		used[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	slove(1);
	cout<<ans;
	return 0;
}
