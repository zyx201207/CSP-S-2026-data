#include<bits/stdc++.h>

using namespace std;

int c1, c2;
string s1,s2;
int s_left,s_right;
int ans[5];

void print(){
	for(int i = 0; i < 4; i++){
		cout << ans[i];
	}
	cout << endl;
}

int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	for(int i = 0; i < 5; i++){
		ans[i] = 0;
	}
	
	if(s1[2] >= 'A' && s1[2] <= 'C'){
		s_left++;
	}else{
		s_right++;
	}
	
	if(s2[2] >= 'A' && s2[2] <= 'C'){
		s_left++;
	}else{
		s_right++;
	}
	
	if(c1 == c2){
		ans[0] = 1;
		
		if((s1[0] * 10 + s1[1]) == (s2[0] * 10 + s2[1])){
			
			ans[1] = 1;
			
			if(s_left == 0 || s_right == 0){
				
				ans[2] = 1;
				
				if(s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1){
					ans[3] = 1;
					print();
				}else{
					print();
				}
				
			}else{
				print();
			}
			
		}else{
			print();
		}
		
	}else{
		print();
	}
	
	return 0;
}
