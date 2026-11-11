#include <bits/stdc++.h>
using namespace std;

int first[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;  i<= n ; i++){
		cin>>first[i];
	}
	for(int gs = 1 ; gs <= n ; gs++){  
		vector<int> v;
		for(int i = gs  ; i <= n ; i++){
			int lid = lower_bound(&v,&(v+v.sizeof)),first[i])-v;
			if( v[lid]  == first[i]){
				for(int j = v.size() ; j >= lid ; j--){
					v.erase(j);
				}
			}
			v.push_back(first[i]);
			
		}
		for(int i = 0 ; i < v.size() ; i++){
			ans[v[i]]++;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cout << ans[i] << ' ' ;
	}
	return 0;
} 



