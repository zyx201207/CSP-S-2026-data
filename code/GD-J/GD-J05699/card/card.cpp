#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int ans[M],c[N];
bool check[N];
int a[N];
stack <int> e;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	bool _c_=false;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i-1]<=a[i]){
			_c_=true;
		}
		else _c_=false;
	}
	bool f=false;
	for (int i=1;i<=n;i++){
		if (a[i-1]!=a[i]){
			f=true;
		}
		else f=false;
	}
	if (_c_){
		for (int i=1;i<=n;i++){
			ans[a[i]]++;
		}
		for (int i=1;i<=m;i++){
			cout << ans[i] << " ";
		}
	}
	else if(f){
		for (int i=1;i<=n;i++){
			ans[a[i]]++;
		}
		for (int i=1;i<=m;i++){
			cout << ans[i] << " ";
		}
	}
	else {
		for (int i=1;i<=n;i++){
			int x;
			x=a[i];
			if (x==n){
				ans[x]=n;
				break;
			}
			e.push(x);
			if (check[x]&&!e.empty()){
				e.pop();
				while(e.top()!=x&&!e.empty()){
					e.pop();
				}
			}
			check[x]=true;
		}
		while(!e.empty()){
			cout << e.top() << " ";
			e.pop();
		}
	}
	return 0;
}
