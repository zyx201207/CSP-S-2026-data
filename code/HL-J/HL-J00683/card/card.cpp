#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n;
vector<ll>cards;
vector<ll>ans(100000);
void play(int x){
	vector<ll>to(m+1);
	vector<ll>time(n);
	vector<ll>temp(n);
	for(int i=x;i<=n;i++){
		if(!to[cards[i]]){
			to[cards[i]]++;
			time[cards[i]]=i;
			temp.push_back(cards[i]);
		}else{
			for(int j=time[cards[i]]+1;j<=i;j++){
				to[temp[j]]--;
				time[temp[j]]=0;
				temp.erase(temp.begin()+j-1,temp.begin()+j);
			}
			time[temp[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(to[i])ans[i]++;
	}
}
int main(){
//	freopen("card.in","r",stdin);       
//	freopen("card.out","w",stdout);  
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		cards.push_back(p);
	}
	for(int i=1;i<=n;i++){
		play(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
