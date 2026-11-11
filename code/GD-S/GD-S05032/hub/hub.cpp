#include<bits/stdc++.h>
using namespace std;
int c,t;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t; 
	for(int i = 1;i<=t;i++){
		if(t % 2 == 0){
			if(i<=t/2) cout << 1 << endl;
			else cout << 2 << endl; 
		}
		else{
			if(i<t/2+1) cout << 1 << endl;
			else cout << 2 << endl; 
		}
	}
	return 0;
} 
