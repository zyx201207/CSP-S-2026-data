#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int wtPush;
	vector<int>cardNTbl;
	vector<int>all(n);
	vector<int>acc(m);
	for(int i=0;i<n;i++) cin>>all[i];
	for(int i=0;i<m;i++) acc[i]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			wtPush=all[j];
			bool f3=true;
			int Mbr;
			for(int k=0;k<cardNTbl.size();k++){
				if(wtPush==cardNTbl[k]){
					f3=false;
					Mbr=k;
					break;
				}
			}
			if(!f3){
				for(int k=cardNTbl.size()-1;k>=Mbr;k--) cardNTbl.pop_back();
			}
			cardNTbl.push_back(wtPush);
		}
		sort(cardNTbl.begin(),cardNTbl.end());
		for(int j=cardNTbl[0];j<m;j++){
			if(cardNTbl.size()<j) break;
			acc[j]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<acc[i]<<' ';
	}
	return 0;
}
