#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],t[300005],y[500005],s,ans[300005];
queue<int> g;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		s = 0;
		for(int j = i;j <= n;j++){
			t[j] = 0;
		}
		for(int j = i;j <= n;j++){
			if(t[a[j]]){
				for(int k = 1;g.front() != a[j];k++){
					y[k] = g.front();
					s = k;
					g.pop();
				}
				for(int k = s + 1;!g.empty();k++){
					t[g.front()]--;
					g.pop();
				}
				for(int k = 1;k <= s;k++){
					g.push(y[k]);
					y[k] = 0;
				}
			}
			g.push(a[j]);
			t[a[j]]++;
		}
		if(i == n){
			while(!g.empty()){
				ans[g.front()]++;
				//cout << g.front() << " " << ans[g.front()] << "\n";
				g.pop();
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
