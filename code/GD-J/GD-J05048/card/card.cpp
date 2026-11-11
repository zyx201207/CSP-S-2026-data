#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	deque<ll> cards(n+5),table;
	vector<bool> used(n+5,false);
	vector<ll> ans(n+5,0),index(n+5);
	for(int i=1;i<=n;++i){
		cin>>cards[i];
	}
	for(ll game=1;game<=n;++game){
		table.push_back(0);
		for(ll i=game;i<=n;++i){
			if(!used[cards[i]]){
				used[cards[i]]=1;
				index[cards[i]]=i;
				table.push_back(cards[i]);
			}else{
				ll ts=table.size();
				for(int j=index[cards[i]];j<ts;++j){
					used[cards[j]]=0;
					index[cards[j]]=0;
					table.pop_back();
				}
				used[cards[i]]=1;
				index[cards[i]]=table.size();
				table.push_back(cards[i]);
			}
		}
		for(int i=0;i<table.size();++i){
			++ans[table[i]];
		}
		table.clear();
		index.clear();
		for(int i=0;i<=n;++i) used[i]=false;
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}










