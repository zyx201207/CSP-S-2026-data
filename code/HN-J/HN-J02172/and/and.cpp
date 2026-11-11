#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
//	cout<<(n&m)<<endl;
	vector<long long>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end(),greater<int>());
	long long ans=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
		//cout<<a[i]<<" ";
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
void dfs(int k,int ans){
	if(k>m){
		cout<<ans;
		return ;
	}
	for(int i=1;i<=n;i++){
		ans=ans&a[i];
		dfs(k+1,ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	return 0;
}
*/
