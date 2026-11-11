#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector <int> v(n+5);
long long a[500005];
long long b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
	

	cin>>n>>m;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	long long total = 0;

	while(total < n){
		v.clear();
		int x = 0;
		for(int i = total; i<n; i++){
			for(int y = 0; y<x; y++){
				if(v[y] == a[i]){
					
					for(int j = y; j<x; j++){
						v[j] = 0;
					}
					x = y;
					break;
				} 
			}
			v[x] = a[i];
			x++;
		}
		for(int i = 0; i<x; i++){
			b[v[i]] ++;
		//cout<<v[i]<<"\n";
		}
		
		total++;
	}
	for(int i = 1; i<=m; i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
