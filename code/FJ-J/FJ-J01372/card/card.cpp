#include<bits/stdc++.h>
using namespace std;

int mfind(const vector<int>& vec,int key){
	if(vec.empty()) return -1;
	for(int i=0;i<vec.size();i++){
		if(vec[i]==key){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;cin>>n>>m;
	vector<int>a(n+1),result(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>cards;
		for(int j=i;j<=n;j++){
			int r=mfind(cards,a[j]);
			if(r!=-1){
				cards.erase(cards.begin()+r,cards.end());
			}
			cards.push_back(a[j]);
		}
		for(int t:cards){
			result[t]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<result[i]<<" ";
	}
	
	
	return 0;
}
