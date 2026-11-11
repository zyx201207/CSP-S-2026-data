#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m;
vector<int> a;
int z;
int ans[500005];
vector<int> p;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a.push_back(0);
	for(int i = 1;i <= n;i++){
		cin>>z;
		a.push_back(z);
	}
	for(int l = 1;l <= n;l++){
		p.clear();
		for(int i = l;i <= n;i++){
			int d = a[i];
			for(int j = p.size()-1;j >= 0;j--){
				if(p[j] == d){
					for(int k = p.size()-1;k >= j;k--){
						p.pop_back();
					}
					break;
				}
			}
			p.push_back(d);
		}
		for(int i = 0;i < p.size();i++){
			ans[p[i]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
