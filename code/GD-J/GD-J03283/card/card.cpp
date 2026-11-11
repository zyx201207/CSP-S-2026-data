#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int a[maxn];
set<int> card;
map<int,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		card.insert(a[i]);
	}
	for(int i = 0;i < card.size();i++){
		cout<<mp[a[i]]<<' ';
	}
	return 0;
}
