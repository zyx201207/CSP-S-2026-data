#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
const int M=3e5+5;
int n, m;
int a[N];
int ans[M];
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> desk;
		vector<int> pos(m);
		for(int j=i;j<=n;j++){
			if(pos[a[j]]){
				desk.erase(desk.begin()+pos[a[j]]-1, desk.end());
			}
			desk.push_back(a[j]);
			pos[a[j]]=desk.size();
		}
		for(const int x:desk){
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
