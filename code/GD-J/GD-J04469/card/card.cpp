#include<bits/stdc++.h>
using namespace std;

int n,m;
int cards[500005];
int cards_id[500005];
vector<int> cot;//cards_on_table
vector<int> cot_id;
int ans[5000005];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>cards[i];
		cards_id[i]=i;
	}
	
	for(int i=0;i<n;i++){
		
		cot.clear();
		for(int j=i;i<n;j++){
			int tmp=find(cot.begin(),cot.end(),cards[j])-cot.begin();
			if(tmp>=cot.size()){
				cot.push_back(cards[j]);
				cot_id.push_back(j);
			}
			else{
				cot.erase(cot.begin()+tmp,cot.end());
				cot_id.erase(cot_id.begin()+tmp,cot_id.end());
				cot.push_back(cards[j]);
				cot_id.push_back(j);
			}
		}
		for(int j=0;j<cot.size();j++){
			ans[cot_id[j]-1]+=1;
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
