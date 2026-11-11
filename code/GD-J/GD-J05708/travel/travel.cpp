#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	int t=1;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >>s2;
	if(c1==c2){
		cout << "1";
	}else{
		t=0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s1[i]){
			t=0;
		}
	}
	cout << t;
	if(t==0){
		cout << 0;
	}else{
		if(s1[2]=='C'&&s2[2]=='D'){
				t=0;
		}
		if(s1[2]=='A'||'B'||'C'){
			if(s2[2]=='A'||'B'||'C'){
				if(s1[2]!=s2[2]){
					cout << t;
				}else{
					cout << t;
					t=0;
				}
			}
		}else{
			if(s1[2]=='D'||'E'){
				if(s2[2]=='D'||'E'){
					if(s1[2]!=s2[2]){
						cout << t;
					}else{
						cout << t;
							t=0;
					}
				}else{
					cout << t;
					t=0;
				}
			}
			
		}
	}
	if(t==0){
		cout << "0";
	}else{
		if(s1[2]=='A'||'B'||'C'){
			if(s2[2]==s1[2]+1||s2[2]==s1[2]-1){
				if(s1[2]!=s2[2]){
					cout << t;
				}else{
					cout << t;
				}
			}else{
				cout << t;
			}
		}else{
		if(s1[2]=='D'||'E'){
			if(s2[2]=='D'||'E'){
				if(s1[2]!=s2[2]){
					cout << t;
					}
				}
			}
		}
	}
}
