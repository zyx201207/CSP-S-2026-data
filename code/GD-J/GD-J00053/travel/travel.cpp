#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	
	int c1,c2; // 车厢 
	string s1,s2; // 座位 
	cin >> c1 >> s1 >> c2 >> s2;
	
	// 同车厢
	if(c1==c2){
		cout<<1;
		// 同一排
		if((s1[0]==s2[0]) && (s1[1]==s2[1])){
			cout<<1;
			// 同侧 
			if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
				if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
					cout<<1;
					// 相邻 
					if(abs(s1[2]-s2[2])==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0<<0;
				}
			}
			else if(s1[2]=='D' || s1[2]=='F'){
				if(s2[2]=='D' || s2[2]=='F'){
					cout<<1;
					if(abs(s1[2]-s2[2])==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0<<0;
				}
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
}
