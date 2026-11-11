#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long x,y,s,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> n >> m;
	while(m--){
		cin >> x >> y;
		while(x--){
			cin >> s >> t;
		}
		cout << rand()%x << endl; 
	}
	return 0;
} 
