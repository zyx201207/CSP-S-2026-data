#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if (c2[2] == 'D'){
		c2[2]='E';
	}
	if (s2[2] == 'D'){
		s2[2]='E';
	}
	if (c1 == s1){
		cout<<"1";
		if (c2[0] == s2[0] && c2[1] == s2[1]){
			cout<<"1";
			int t=0;
			if (c2[2] == 'E' || c2[2] == 'F'){
				t++;
			}
			if (s2[2] == 'E' || s2[2] == 'F'){
				t++;
			}
			if (t == 2 || t == 0){
				cout<<"1";
				if (min(c2[2],(s2[2]))+1 == max(c2[2],s2[2])){
					cout<<"1";
				}else {
					cout<<"0";
				}
			}else {
				cout<<"00";
			}
		}else {
			cout<<"000";
		}
	}else {
		cout<<"0000";
	}
	return 0;
} 
