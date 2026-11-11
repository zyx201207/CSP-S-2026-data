#include<bits/stdc++.h>
using namespace std;
int n,m,a,sum,ans,k,imax=0;
int y[200005];
bool p=0;
bool cmp(int x,int y){
	if(x>y) return true;
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>y[i];
	}
	sort(y+1,y+n+1,cmp);
	ans=y[1];
	for(int i=1;i<=m;i++){
		ans=min(ans,y[i]);
	}
	cout<<ans;
	return 0;
}
