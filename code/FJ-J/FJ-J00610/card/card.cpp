#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[500010],top;
map<int,int> ma;
vector<pair<int,vector<int>>> v;
vector<int> nul;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool qA = true;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] < a[i - 1]){
			qA = false;
		}
		if(ma[a[i]] != 0){
			b[ma[a[i]]] = ma[a[i]];
		}
		ma[a[i]] = i;
	}
	if(qA){
		for(int i = 1;i <= m;i++){
			cout<<"1 ";
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		if(b[i] == 0){
			b[i] = b[i - 1];
		}
		bool q = true;
		for(int j = 0;j < top;j++){
			if(v[j].first == a[i]){
				q = false;
				while(v[j].second.size() < i + 1){
					v[j].second.push_back(0);
				}
				v[j].second[(b[i] == i ? 0 : b[i]) + 1] += 1;
				v[j].second[i + 1] -= 1;
			}
		}
		if(q){
			v.push_back({a[i],nul});
			while(v[top].second.size() < i + 1){
				v[top].second.push_back(0);
			}
			v[top].second[(b[i] == i ? 0 : b[i]) + 1] += 1;
			v[top].second[i + 1] -= 1;
			top++;
		}
	}
	int ans[300010] = {};
	for(int i = 0;i < top;i++){
		for(int j = 1;j < v[i].second.size();j++){
			v[i].second[j] = v[i].second[j - 1] + v[i].second[j];
			if(v[i].second[j] != 0){
				ans[v[i].first]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

