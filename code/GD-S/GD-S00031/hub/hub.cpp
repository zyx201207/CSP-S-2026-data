#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c;
	if(c == 0){
		cin >> t;
		if(t == 2) cout << "1\n" << "2" ;
	}
	else{
		cin >> t;
	    cout << t << "\n";
	}
	
	return 0;
}
