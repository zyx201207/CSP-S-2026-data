#include<bits/stdc++.h>
using namespace std;
vector<int> a,ycards;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a=vector<int>(m,0);
	for(int i=0,u;i<n;i++){
		cin>>u;
		ycards.push_back(u-1);
	}
	for(int i=0;i<n;i++){
		vector<bool> hash(m,0);
		stack<int> cards;
		for(int j=i;j<n;j++){
			if(hash[ycards[j]]){
				while(cards.top()!=ycards[j]){
					hash[cards.top()]=0;
					cards.pop();
				} 
			}else{
				hash[ycards[j]]=1;
				cards.push(ycards[j]);
			}
		}
		while(!cards.empty()){
			a[cards.top()]++;
			cards.pop();
		}
	}
	for(int i=0;i<m;i++)cout<<a[i]<<' ';
	fclose(stdin);
	fclose(stdout);
}
