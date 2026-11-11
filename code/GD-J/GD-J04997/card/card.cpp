#include <bits/stdc++.h>
using namespace std;
stack <long long> desk;
unordered_map <long long,bool> card;
long long k[300005],cnt[300005];
long long n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>k[i];
	}
	for(int i=1;i<=n;i++){
		card.clear();
		//cout <<"µÚ" <<i <<":\n"; 
		for(int j=i;j<=n;j++){
			if(card[k[j]]==1){
				while(desk.top()!=k[j]){
					//cout <<"pop:" <<desk.top()<<"\n";
					card[desk.top()]=0;
					desk.pop();
				}
			}else{
				desk.push(k[j]);
				//cout <<"push:" <<desk.top()<<"\n";
				card[k[j]]=1;
			}
			
		}
		
		while(!desk.empty()){
			cnt[desk.top()]++;
			//cout <<desk.top();
			desk.pop();
		}
		//cout <<"\n";
	}
	for(int i=1;i<=m;i++){
		cout <<cnt[i] <<" ";
	}
}
