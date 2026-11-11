#include <bits/stdc++.h>
using namespace std;

int a[100010], cnt[100010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool isa=1;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]<a[i-1]) isa=0;
	}
	if(isa==1){
		for(int i=1; i<=n; i++){
			if(a[i]!=a[i+1]) cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1; i<=n; i++){
		vector<int> v;
		for(int j=i; j<=n; j++){
			int f=-1;
			for(int k=0; k<v.size();k++){
				if(v[k]==a[j]){
					f=k;
					break;
				}
			}
			vector<int>vv;
			if(f!=-1){
				for(int k=0; k<f; k++){
					vv.push_back(v[k]);
				}
				v=vv;
			}
			v.push_back(a[j]);
		}
		for(auto j:v){
			cnt[j]++;
		}
	}
	for(int i=1; i<=m; i++) cout<<cnt[i]<<" ";
	return 0;
}