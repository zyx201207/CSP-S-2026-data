#include <bits/stdc++.h>
using namespace std;
int n;
string s,c[100];
int k[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> k[i] >> c[i]; 
	}
	if(n==1){
		cout << "0";
		return 0;
	}
	if(c[1] == c[2]){
		cout << "0";
		
	}else{
		if(k[2] > k[1]){
			cout << k[1];
		}else if(k[1] > k[2]){
			cout << k[2];
		}else{
			cout << k[2];
		}
	}
	

	return 0;
}
