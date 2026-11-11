#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
int n,m,a[100005],ans[100005];
vector<int> v;
bool vis[100005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<v.size();j++){
			if(v[j]==a[i]){
				v.erase(v.begin(),v.begin()+j);
			}
		}
		v.push_back(a[i]);
		for(int k=0;k<v.size();k++){
			ans[v[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
