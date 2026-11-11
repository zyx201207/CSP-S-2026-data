#include <bits/stdc++.h>
using namespace std;
vector<int>cards;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,v;
	cin>>n>>m;
	for(int i =0;i<n;i++){
		cin>>v;
		cards.push_back(v);
	}
	
	for(int j =0;j<n;j++){
		
		for(int i=j;i<n;i++){
			bool sign = 0;
			for(int k =0;k<n;k++){
				if(cards[k]==cards[i])sign =1;
			}
			if(!sign)cards.push_back(cards[i]);
			else cards.erase();
		}
	}
	
	
	return 0;
}