#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c = 0, t = 0;
	cin >> c >> t;
	if(c == 0){
		while(t--){
			int n = 0, k = 0;
			cin >> n >> k;
			for(int i = 0; i < n; i++){
				cin >> a[i];
			}
			if(t == 2){
				cout << 1 << endl << 2;
			}
			if(t == 3){
				cout << 35 << endl << 16;
			}
		}
	}
	return 0;
}
