#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		vector<int>game(n);
		unordered_map<int,int>card;
		int l=0;
		for(int j=i;j<n;j++){
			auto it=card.find(a[j]);
			if(it!=card.end()){
				for(int k=l-1;k>=it->second;k--){
					card.erase(game[k]);
					game.pop_back();
					l--;
				}
			}game[l++]=a[j];
			card[a[j]]=l-1;
		}for(int j=0;j<l;j++){
			cnt[game[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
} 
