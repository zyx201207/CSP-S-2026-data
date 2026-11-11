#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> cnt;
vector<int> a;
int n, m;
void work(int posssss){
	deque<int> q;
	for(int i=posssss; i<=n; i++){
		if(find(q.begin(), q.end(), a[i])!=q.end()){
			while(q.back()!=a[i])q.pop_back();
		}
		else q.push_back(a[i]);
	}
	for(auto&e:q)cnt[e]++;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	a.resize(n+2);
	bool flg=true;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]<a[i-1])flg=false;
	}
	if(flg){
		for(int i=1; i<=n; i++){
			if(a[i]!=a[i+1]){
				cout<<i<<" ";
			}
		}
	}
	for(int i=1; i<=n; i++){
		work(i);
	}
	for(int i=1; i<=m; i++)cout<<cnt[i]<<" ";
	return 0;
}
