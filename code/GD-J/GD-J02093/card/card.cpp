#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 5e5+10;
constexpr int M = 3e5+10;
int a[N],jump[N],ton[M],ans[M];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=n;i>=1;i--){
		jump[i] = ton[a[i]];
		if(!ton[a[i]])
			ton[a[i]] = i;
	}
	for(int i=1;i<=n;i++){
		int p = i;
		while(true){
			while(jump[p])
				p = jump[p];
			ans[a[p++]]++;
			if(p>n) break;
		}
	}
	for(int i=1;i<=m;i++)
		cout << ans[i] << " ";
	return 0;
}
