#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
vector<int > e[500005];
map<int ,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i =1;i <= n ;++i ){
		cin >> a[i];
	}
	for(int i =n;i >= 1;--i){
		if(mp[a[i]]){
			e[i] = e[mp[a[i]]];
			mp[a[i]] = i;
		}else{
			mp[a[i]] = i;
			e[i] = e[i+1];
			e[i].push_back(a[i]);
		}
	}
	for(int i =0;i <= n ;++i ){
		for(int j =0;j < e[i].size();++j){
			++ans[e[i][j]];
		}
	}
	for(int i =1;i <= m;i++){
		cout << ans[i] << ' ';
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
