#include<bits/stdc++.h>
using namespace std;
long long o,n,m,x,y,t[500010],a[500010],b[510][510],u,v,c;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> o >> n >> m >> x >> y;
	for(int i = 0;i < m; i++){
		cin >> t[i];
		c += t[i];
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 1; j <= 2*a[i]; j++){
			cin >> b[i][j];
			if(j % 2 == 0){
				c += b[i][j];
			}
		}
	}
	while(y--){
		cin >> u >> v;
		cout << c << endl;
		c = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
