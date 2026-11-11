#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans1;
void dfs(int s,int res,int q){
	//cout << s<<' '<< res <<' '<< q<<'\n';
	if(s==m){
		if(ans1<res)ans1=res;
		//cout << s<<' '<< ans1 <<' '<< q<< "qqqq" <<'\n';
		return;
	}
	else if(q>n)return;
	else{
		if(s!=0)
		dfs(s+1,res&a[q],q+1);
		else dfs(s+1,a[q],q+1);
		dfs(s,res,q+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<long long>());
	long long ans=a[0];
	if(n<=20){
		dfs(0,0,0);
		cout << ans1;	
	}
	else{
		for(int i = 1;i<m;i++){
		ans=ans&a[i];
	}cout << ans;
	}
	
	return 0;
}
