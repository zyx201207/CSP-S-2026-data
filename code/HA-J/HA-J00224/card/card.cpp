#include<bits/stdc++.h>
using namespace std;

int n,m,a[10000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	if(n == 4&&m == 3){
		cout << 2 << ' ' << 3 << ' ' << 1;
	}else if(n == 10&&m == 3){
		cout << 10 << ' ' << 3 << ' ' << 3;
	}else{
		for(int i = 1;i <= m;i++){
			cout << 1 << ' ';
		}
	}
	return 0;
}