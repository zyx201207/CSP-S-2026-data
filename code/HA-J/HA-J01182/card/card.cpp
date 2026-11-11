#include<bits/stdc++.h>
using namespace std;
const int N= 5e5+5;
int n,a[N],m,ans[N],vis[N];
vector<int> app[N];
string s1,s2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >>m;
	for(int i = 1;i<=n;i++){
		cin >>a[i];
		app[a[i]].push_back(i);
	}
	for(int i = 1;i<=n;i++){
		int add=app[a[i]].size();
		if(vis[a[i]]) continue;
		vis[a[i]]=1;
		for(int j = i;j<=n;){
			j=app[a[j]][app[a[j]].size()-1];
			ans[a[j]]+=add;
			j++;
		}
	}
	for(int i = 1;i<=m;i++) cout <<ans[i] << " ";
}
