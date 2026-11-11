#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[300010],tong[300010];
vector<int> card;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k;k<card.size();k++){
				if(a[k]==a[j]){
					int len=card.size();
					for(int l=1;l<len;l++){
						card.erase(card.begin()+k);
					}
					break;
				}
			}
			card.push_back(a[j]);
		}
		for(int j=card.size()-1;j>=0;j--){
			ans[card[j]]++;
			card.pop_back();
		}
	}
	for(int i=1;i<=n;i++){
		if(tong[a[i]]!=0){
			continue;
		}
		tong[a[i]]++;
		cout<<ans[a[i]]<<' ';
	}
	return 0;
}
