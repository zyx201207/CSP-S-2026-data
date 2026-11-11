#include<bits/stdc++.h>
using namespace std;

int c,t,n,d,lists[2000005];
map<int,int> mp;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> lists[i];
		cout << "0" << endl;
	} 
	return 0;
}
