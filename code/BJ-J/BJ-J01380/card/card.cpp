#include <iostream>
#include <cstring>
using namespace std;

int n,m,card[500005],nextt[500005],second[300005],cnt[300005];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		 cin >> card[i];
		 nextt[second[card[i]]] = i;
		 second[card[i]] = i;
	}
	memset(second,0,sizeof(second));
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(!second[card[j]]){
				cnt[card[j]]++;
			}
			second[card[j]] = 1;
			if(nextt[j] != 0){
				j = nextt[j] - 1;
			}
		}
		memset(second,0,sizeof(second));
	}
	for(int i = 1;i <= m;i++) cout << cnt[i] << ' ';
	return 0;
}
