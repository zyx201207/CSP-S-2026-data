#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int minn =0x3f3f3f3f; 
		for(int i = 0;i<n-1;i++){
			int a,b;
			cin >> a >> b;
			minn = min(minn,b-a);
		}
		cout << minn << endl;
	}
	return 0;
}
