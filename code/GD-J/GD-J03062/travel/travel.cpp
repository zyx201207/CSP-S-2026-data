#include<bits/stdc++.h>
using namespace std;
char c1[2],c2[2];
char s1[3],s2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i <= 1;i++) cin >> c1[i];
	for(int i = 0;i <= 2;i++) cin >> s1[i];
	for(int i=0;i <= 1;i++) cin >> c2[i];
	for(int i = 0;i <= 2;i++) cin >> s2[i];
	if(c1[1] == c2[1]&&c1[0] == c1[0]){
		cout << 1;
	}else{
		for(int i = 1;i <= 4;i++) cout << 0;
		return 0;
	}
	if(s1[0]==s2[0] && s1[1] == s2[1]){
		cout << 1;
	}else{
		for(int i = 1;i <= 3;i++) cout << 0; 
		return 0;
	}
	if(s1[2] == 'A' || s1[2] =='B'||s1[2] =='C'){
		if(s2[2] != 'D'&&s2[2]!='F'){
			cout << 1;
		}else{
			for(int i = 1;i <= 2;i++) cout << 0;
			return 0;
		}
	}else{
		if(s2[2] != 'D'&&s2[2]!='F'){
			for(int i = 1;i <= 2;i++) cout << 0;
			return 0;
		}else{
			cout << 1;
		}
	}
	char k = s1[2];
	if(s2[2] > k) k = s2[2];
	if(k-s1[2]<=1&&k-s2[2]<=1){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
