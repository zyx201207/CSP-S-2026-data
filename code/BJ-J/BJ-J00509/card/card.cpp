#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	int dianshu[m+5] = {};
	int card[n+5] = {};
	
	for(int i = 0;i<n;i++){
		cin>>card[i];
	}
	
	for(int i = 0;i<n;i++){
		vector<int> play;
		for(int j = i;j<n;j++) {
			play.push_back(card[j]);
			int cnt = 0;
			for(int ls = play.size()-2;ls>=0;ls--){
				cnt++;
				if(play[ls]==play[play.size()-1]){
					while(cnt--) play.pop_back();
					break;
				}
			}
		}
		
		sort(play.begin(),play.end());
		for(int j = 0;j<play.size();j++){
			if(play[j]==play[j-1]) continue;
			dianshu[play[j]]++;
		}
	}
	
	for(int i = 1;i<=m;i++){
		cout<<dianshu[i]<<" ";
	}
	
	return 0;
}
