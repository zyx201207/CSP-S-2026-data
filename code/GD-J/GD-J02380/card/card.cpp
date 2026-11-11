#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[500005];
int t[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0); 
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		t[i] = 0;
	}
	
	vector<int> v;
	for(int i = 1;i <= n;i++){
		v.clear();
		for(int j = i;j <= n;j++){
			//cout<<a[j]<<" ";
			if(find(v.begin(),v.end(),a[j]) != v.end()){
				while(*v.end() != a[j]){
					v.pop_back(); 
				} 
				v.push_back(a[j]);
			}
			else
				v.push_back(a[j]);
		}
		//cout<<'\n'; 
		for(auto p : v){
			t[p]++;
			//cout<<p<<" ";
		}
		//cout<<"\n";
	} 
	for(int i = 1;i <= m;i++){
		cout << t[i] << ' ';
	}
	return 0;
} 
