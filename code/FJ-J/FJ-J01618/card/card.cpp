#include <bits/stdc++.h>
using namespace std;
int game(int want,vector<int> &cards,int n){
	deque<int> desk;
	for(int i=0;i<cards.size();i++){
		
		desk.push_back(cards[i]);
		
		for(int j=0;j<i-1;j++){
			if(desk[j]==cards[i]){
				for(int k=j;k<i&&desk.size()>0;k++){
					desk.pop_back();
				}
			}
		}
	}
	
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m=0;
	cin>>n>>m;
	vector<int> list(m,0),cards(n,0);
	for(int i=0;i<n;i++){
		int y=0;
		cin>>y;
	}
	for(int i=0;i<m;i++){
		vector<int> bcards=cards;
		list[i]=game(i,bcards,n);
	}
	return 0;
}