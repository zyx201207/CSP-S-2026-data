#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> box;
vector<int> desk;
vector<int> hand;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	hand.resize(n);box.resize(m+1);
	for(int i=0;i<n;i++){
		cin>>hand[i];
	}
	for(int i=0;i<n;i++){//局数
		for(int j=i;j<n;j++){//牌数
			int now_card=hand[j];
			bool flag=0;
			for(int k=0;k<desk.size();k++){
				if(desk[k]==now_card){
					desk.resize(k);
					desk.push_back(now_card);
					flag=1;
					break;
				}
			}
			if(!flag){
				desk.push_back(now_card);
			}
		}
		vector<bool> vis(m+1);
		for(int j=0;j<desk.size();j++){
			if(!vis[desk[j]]){
				vis[desk[j]]=1;
				box[desk[j]]++;
			}
		}
		desk.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<box[i]<<" ";
	}
	return 0;
}
