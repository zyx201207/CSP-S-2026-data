#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> v,a;
bool b=true;
long long maxn=-1;
void dfs(long long start){
	if(start>=n) return ;
	if(v.size()==m){
		long long ans=v[0];
		for(int i=1;i<m;i++){
			ans&=v[i];
		}
		maxn=max(maxn,ans);
		return ;
	}
	dfs(start+1);
	v.push_back(a[start]);
	dfs(start+1);
	v.pop_back();
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
		if(pow(2,log2(x+1))!=x+1){
			b=false;
		}
	}
	if(m==1){
		for(int i=0;i<n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		maxn=a[0];
		for(int i=1;i<n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		maxn=a[0];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(b==true){
		sort(a.begin(),a.end());
		cout<<a[n-m];
		return 0;
	}
	dfs(0);
	cout<<maxn;
	return 0;
}
