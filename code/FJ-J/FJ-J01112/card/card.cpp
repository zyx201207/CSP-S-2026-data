#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	vector<int> cards,cnt;
	cnt.resize(m);
	int head=0;
	for(int i=0;i<n;i++){
		cin>>a;
		cards.push_back(a);
	}
	for(int i=1;i<=n;i++){
		vector<int> cardQueue;
		if(cards[i-1]==cards[n-1]){
			cnt[cards[i-1]-1]++;
			continue;
		}
		for(int j=i-1;j<n;j++){
			int isFind=-1; 
			for(int z=head;z<cardQueue.size();z++){
				if(cardQueue[z]==cards[j]) isFind=z;
			}
			if(isFind==-1) cardQueue.push_back(cards[j]);
			else{
				cardQueue.erase(cardQueue.begin()+isFind+1,cardQueue.end());
			}
		}
		for(int j=head;j<cardQueue.size();j++) {
			cnt[cardQueue[j]-1]++;
		}
	}
	for(int i:cnt) cout<<i<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
