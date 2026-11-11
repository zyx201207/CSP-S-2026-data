#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	stack<int> s;
	set<int> x;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			int si = x.size();
			x.insert(a[j]);
			if(x.size() == si){
				while(s.top() != a[j]){
					x.erase(s.top());
					s.pop();
				}
			}
			else{
				s.push(a[j]);
			}
		}
		for(int k : x){
			t[k]++;
		}
		while(!s.empty())s.pop();
		x.clear();
	}
	for(int i = 1;i <= m;i++){
		cout << t[i] << " ";
	}
	return 0;
}
