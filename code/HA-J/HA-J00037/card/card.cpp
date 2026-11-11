#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio (false);
	cin.tie (0);

	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);

	int n,m;
	cin >> n >> m;
	//cerr << n << " " << m;
	//cerr << "\n\n";
	
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
		//cerr << a[i] << ' ';
	}
	//cerr << "\n\n";
	
	vector<int> cnt(m+1,0);
	
	for(int i = 0;i < cnt.size()-1;i++){
		//cerr << cnt[i] << " ";
	}
	//cerr << "\n\n";
	
	for(int i = 1;i <=n;i++){
		//cerr <<"i="<< i;
		//cerr << "\n\n";
		
		int have = 0;
		vector<int> table;
		table.reserve(n);
		for(int j = i;j <= n;j++){
			//cerr <<"j="<< j;
			//cerr << "\n\n";
			
			
			for(int k = 0;k < have-1;k++){
				//cerr <<"k="<< k;
				//cerr << "\n\n";
				
				if(table[k] == j){
					for(int l = k;l < n;l++){
						//cerr <<"l="<< l;
						//cerr << "\n\n";
						
						table.pop_back();
						have--;
					}
					break;
				}
			}
			table.push_back(j);
			have++;
		}
		
		//cerr << "table= ";
		for(int j = 0;j < have-1;j++){
			//cerr << table[j] << " ";
		}
		//cerr << "\n\n";
		
		for(int j = 0;j < have-1;j++){
			//cerr <<"j1="<< j;
			//cerr << "\n\n";
			
			cnt[table[j]]++;
		}
		for(int j = 0;j <=m;j++){
			//cerr << cnt[j] << " ";
			
		}
		//cerr << "\n\n";
	}
	
	for(int i = 1;i <=m;i++){
		//cerr <<"i="<< i;
		//cerr << "\n\n";
		
		cout << cnt[i] << " ";
	}
	cout << "\n";
	
	return 0;
}

