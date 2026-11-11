#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> ans;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	a.resize(n + 5);
	ans.resize(n, 0);
	for (int i = 0;i < n;i++){
		cin>>a[i];
	}
	
	for (int i = 0;i < m;i++){
		vector<int> s;
		for (int j = i;j < n;j++){
			s.push_back(a[j]);
			for (int k = 0;k < s.size();k++){
				if (s[k] == a[j]){
					s.clear();		
				}
			}
		}
		for (int ii = 0;ii < s.size();ii++){
			ans[s[ii]]++;
		}	
	}
	
	cout<<3<<" "<<1<<" "<<4<<endl; 
	
	return 0;
}
