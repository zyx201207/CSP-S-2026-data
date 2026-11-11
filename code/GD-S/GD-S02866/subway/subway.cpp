#include <bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[1000005],a[10005][10005],t[10005][10005],xl[1000005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		xl[i] = x;
		for(int j = 1; j <= x;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		for(int i = 1;i <= n;i++){
			if(a[i][1] == x){
				
			}
		}
	}
	return 0;
} 
