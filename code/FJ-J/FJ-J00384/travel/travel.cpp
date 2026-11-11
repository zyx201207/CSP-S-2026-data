#include<bits/stdc++.h>
using namespace std;
int mian(){
	freopen("travel1.in","r",stdin);
	freopen(" travel1.ans","w",stdout);
	int s1,s2;
	char c1,c2;
	cin >> s1 >> s2 >> c1 >> c2;
	if(s1 != 1 && s1 != 16 && s2 != 1 && s2 != 16 ){
		if(s1==s2){
			cout << 1;
		}
		if(c1 == c2){
			cout << 1;
		}
		if(c1 == c2){
			cout << 1;
		}
		if(c1 < 'C' && c2 < 'C' || 'C' < c1 < 'F' && 'C' < c2 < 'F'){
			cout << 1;
		}
	}
	return 0;
}
