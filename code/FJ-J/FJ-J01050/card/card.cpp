#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
int point[6000];
int card[6000];
vector<int> pre;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int game=1;game<=n;game++){
		for(int i=game;i<=n;i++){
			for(int j=0;j<pre.size();j++){
				if(pre[j]==card[i]){
					pre.erase(pre.begin()+j,pre.end());
				}
			}
			pre.push_back(card[i]);
		}
		while(!pre.empty()){
			point[pre.back()]++;
			pre.pop_back();
		}
	}
	for(int i=1;i<=k;i++){
		cout<<point[i];
		if(i==k){
			break;
		}
		cout<<" ";
	}
	return 0;
}
