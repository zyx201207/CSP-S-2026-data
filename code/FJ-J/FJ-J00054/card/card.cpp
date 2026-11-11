#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+3;
int n,m,a[MAXN];
int ans[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		vector <int> cards;
		for(int j=1;j<=n;j++) cards.emplace_back(a[j]);
		int index=i;
		for(index;index<=n;index++){
			int nindex=-1;
			for(int k=0;k<(int)cards.size();k++) if(cards[k]==a[index]){
				nindex=k+1;
				break;
			}
			if(~nindex){
				while((int)cards.size()!=nindex) cards.pop_back();
			}else cards.emplace_back(a[index]);
		}
		for(int j=0;j<(int)cards.size();j++) ans[cards[j]]++;
	}
	for(int i=1;i<=m;i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
