#include<bits/stdc++.h>
using namespace std;
#define itn int
itn n,m,c,maxn,ma[200010],a[200010],p;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= m;i++){
		maxn = 0;
		for(int j = 1;j <= n;j++){
			maxn = max(maxn,a[j]);
			p = j;
		}
		ma[p] = maxn;
		a[p] = 0;
	}
	for(int i = 1;i <= n;i++){
		if(ma[i] != 0){
			if(c == 0){
				c = ma[i];
			}
			else{
				c = c & ma[i];
			}
		}
	}
	cout << c;
	return 0;
}
