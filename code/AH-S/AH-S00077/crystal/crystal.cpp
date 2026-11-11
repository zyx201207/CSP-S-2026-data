#include <bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int a[500010];
int js(){
	map<long long int,int> ti;
	int maxn=INT_MIN;
	for(int i=1; i<=n; i++){
		ti[a[i]]++;
		maxn=max(maxn,ti[a[i]]);
	}
	return maxn;
}
void solve(long long int add,int pos){
	if(pos>n) return;
	if(add==m) ans=max(ans,js());
	for(int i=0; i<=(m-add); i++){
		a[pos]+=i;
		solve(add+i,pos+1);
		a[pos]-=i;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	solve(0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
