#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
map <int,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	bool f = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i >= 2 && a[i-1] > a[i]){
			f = 0;
		}
	}
	if(f){
		for(int i = 1;i <= n;i++){
			unordered_set <int> se;
			for(int j = i;j <= n;j++){
				se.insert(a[j]);
			}
			for(auto i:se){
				mp[i]++;
			}
		}
		for(auto i:mp) cout << i.second << ' ';
		return 0;
	}
	for(int i = 1;i <= n;i++){
		queue <int> q,qe;
		vector <int> v;
		v.resize(1,-1);
		for(int j = i;j <= n;j++){
			for(int k : v){
				if(a[j] == k){
					bool f = 1;
					while(!q.empty()){
						if(q.front() == a[j]){
							f = 0;
						}if(f){
							qe.push(q.front());
						}
						q.pop();
					}
				}
			}
			v.push_back(a[j]);
			while(!qe.empty()){
				q.push(qe.front());
				qe.pop();
			}
			q.push(a[j]);
		}
		
		while(!q.empty()){
			mp[q.front()]++;
			q.pop();
		}
	}
	for(auto i:mp) cout << i.second << ' ';
	return 0;
}

