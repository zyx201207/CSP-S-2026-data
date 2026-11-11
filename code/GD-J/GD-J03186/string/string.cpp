#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	int a;
	int sam = 0;
	float p = 0;
	string c;
	cin >> n;
	for(int i = 0;i <= n;i++){
		cin >> a >> c;
		for(int j = 0;i < a;j++){
			s += c;
			p++;
		}
		if(int(p) % 2 == 0){
			for(int k = 0;k <= p/2;k++){	
				if(s[k] != s[p-k]){
					s[p-k] = s[k];
					sam++;
				}
			}
		}
		if(int(p) % 2 != 0){
			for(int k = 0;k <= ceil(p/2.0);k++){
				if(s[k] != s[p-k]){
					s[p-k] = s[k];
					sam++;
				}
			}
		}
	}
		
	cout << sam;
	return 0;
} 
