#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool n = 0,m = 0;
	string zc1 = "000",zc2 = "000";
	char a[5] = {'A','B','C','D','F'};
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		for(int i = 0;i < 2;i++){
			zc1[i] = s1[i];
			zc2[i] = s2[i];
		}
		if(zc1 == zc2){
			cout << 1;
			n = 0;
			m = 0;
			for(int i = 0;i < 3;i++){
				if(s1[2] == a[i]){
					n = 1;
				}
				if(s2[2] == a[i]){
					m = 1;
				}
			}
			if(n && m){
				cout << 1;
				if(s1[2] == 'B' || s2[2] == 'B'){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else if(!(n || m)){
				cout << 1 << 1;
			}
			else{
				cout << 0 << 0;
			}
		}
		else{
			cout << 0 << 0 << 0;
		}
	}
	else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
} 
