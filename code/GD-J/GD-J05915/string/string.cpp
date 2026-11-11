#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a,lenn = 0,ans = 0;
	string s,b;
	cin >>n;
	for(int j = 0;j < n;j++){
		cin >> a >>b;
		lenn += a;
		for(int i = 0;i < a;i++){
		s += b;
		}
	}
	
	if(lenn % 2 == 0){
		for(int i = 0;i < lenn;i++){
		if(s[i] != s[lenn-1-i]){
				s[lenn-1-i] = s[i];
				ans += 1;
			}		
		}		
	}else{
		for(int i = 0;i < lenn;i++){
			if(i == (lenn+1)/2){
				break;
			}
			if(s[i] != s[lenn-1-i]){
				s[lenn-1-i] = s[i];
				ans += 1;
			}		
		}	
	}
	
	cout << ans;
	return 0;
}
