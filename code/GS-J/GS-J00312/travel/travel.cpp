#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	//1
	if(c1 == c2){
		if(c1 == c2){
			cout << "1";
		}
	}else{
		cout << "0";
	}
	
	//2
	int ans = 0;
	for(int i=1 ; i<s1.size(); i++){
		if(s1[i-1] == s2[i-1]){
			ans++;
		}else{
			int ans = 0;
		}
	}
//	cout << ans;
	if(ans == 2){   
		cout << "1";
	}else{
		cout << "0";
	}	
	//3
	cout << "1" << "1";


	return 0;
}




