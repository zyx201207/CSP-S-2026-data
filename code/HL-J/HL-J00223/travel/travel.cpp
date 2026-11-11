#include<bits/stdc++.h>
using namespace std;
int tot[100];
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a , b;
	string s1 , s2;
	cin >> a >> s1 >> b >> s2;
	if(a == b) cout << 1;
	else{cout << "0000";return 0;}
	int a1 = s1[0] + s1[1] - '0' - '0';
	int b1 = s2[0] + s2[1] - '0' - '0';
	if(a1 == b1) cout << 1;
	else{cout << "000";return 0;}
	tot[s1[2] - 'A' + 1] ++;
	tot[s2[2] - 'A' + 1] ++;
	int flag1 , flag2;
	flag1 = flag2 = 0;
	for(int i = 1;i <= 3;i ++) if(tot[i]) flag1 ++;
	for(int i = 4;i <= 5;i ++) if(tot[i]) flag2 ++;
	if(flag1 == 2){
		cout << 1;
		if((tot[1] && tot[2]) || (tot[2] && tot[3])) cout << 1;
		else cout << 0;
	}
	else if(flag2 == 2) cout << 11;
	else cout << "00";
	return 0;
}
