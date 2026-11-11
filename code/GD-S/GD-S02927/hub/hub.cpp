#include <bits/stdc++.h>
#define cls(x) memset(x, 0, sizeof(x))
using namespace std;

struct City{
	int id=-1;
	char flag = 0;
	vector<int> linked;
	
	void sign(City* cities){
		for (int i = 0;i<linked.size();i++){
			cities[linked[i]].linked.erase(id);
		}
		for (int i = 0;i<linked.size();i++){
			cities[linked[i]].sign(cities);
		}
	}
};

void solve(){
	int n, k;
	scanf("%d %d", &n, &k);
	City cities[n];
	for (int i = 1;i<n;i++){
		cities[i].id=i;
		int u,v;
		scanf("%d %d", &u, &v);
		cities[u].linked.push_back(v)
		cities[v].linked.push_back(u)
	}
	
	int p = n, l = 1;
	
	for (int i = 0;i<cities.size();i++){
		if (cities[i].linked.size() == 1) {
			cities[i].flag = 1;
			p--;
		}
	}
	
	while (p){
		l++;
		for (int i = 0;i<cities.size();i++){
			int cnt = 0;
			for (int j = 0;j<cities[i].linked.size();j++){
				if (!cities[i].linked[j].flag) cnt++;
			}
			if (cnt == 1) cities[i].flag = l;
		}
	}
	
	int mi = 0;
	for (int i = 0;i<n;i++){
		if (cities[i].flag == l){
			citied[i].sign(cities);
			mi = i;
			break;
		}
	}
	for (int i = 0;i<n;i++){
		cities[i].flag = 0;
	}
	queue<int> q;
	q.add(mi);
	while (!q.empty() && k--){{
		int t = q.pop();
		cities[t].flag = 1;
		for(int i = 0;i<cities.linked.size();i++){
			q.add(cities.linked[i]);
		}
	}
	
	
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c,t;
	scanf("%d %d", &c,&t);
	while (t--) solve();
	
	
	return 0;
} 
