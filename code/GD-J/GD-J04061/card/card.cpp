#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int> card(n+1);
	for(int i=1;i<=n;i++) cin>>card[i];
	
	vector<int> cnt(m+1,0);
	for(int k=1;k<=n;k++){ 
		stack<int> s;
		vector<int> had(m+1,false);
		for(int i=k;i<=n;i++){
			if(had[card[i]]){
				while(!s.empty()&&s.top()!=card[i]){
					had[s.top()]=false;
					s.pop();
				}
			}else{
				s.push(card[i]);
				had[card[i]]=true;
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
		if(i!=m) cout<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
