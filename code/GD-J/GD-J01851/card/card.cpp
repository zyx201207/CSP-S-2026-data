#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+1,M=3e5+1; 
ll n,m,a[N],cnt[M];
vector<int> v;
void dfs(){
	stack<int> c;
	for(int i=0;i<v.size();i++){
		
		stack<int> s=c;
		int p=0;
		while(s.size()){
			int t=s.top();
			p++;
			if(t==v[i]) break;
			s.pop();
		}
		if(s.empty()) p=0;
		while(p--) c.pop();
		c.push(v[i]);
	}
	while(c.size()){
		cnt[c.top()]++;
		c.pop();
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=1;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]) f=0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			cnt[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		v.clear();
		for(int j=i;j<=n;j++){
			v.push_back(a[j]);
		}
		dfs();
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
		if(i<m) cout<<' ';
	}
	return 0;
}
