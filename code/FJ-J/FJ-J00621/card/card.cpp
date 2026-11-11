#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5,MAXM = 3e5+5;
int a[MAXN],cnt[MAXM];
vector<int> c;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++) cin >> a[i];
	for(int l=1 ; l<=n ; l++){
		c.clear();
		for(int i=l ; i<=n ; i++){
			for(int j=0 ; j<c.size() ; j++){
				if(c[j] == a[i]){
					while(c.size() > j) c.erase(c.begin()+j);
					break;
				}
			}
			c.push_back(a[i]);
		}
		for(int i=0 ; i<c.size() ; i++){
			cnt[c[i]]++;
			//cout << c[i] << ' ';
		}
//		cout << endl;
	}
	for(int i=1 ; i<=m ; i++) cout << cnt[i] << ' ';
	return 0;
}
