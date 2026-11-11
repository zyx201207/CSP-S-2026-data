/*
小R没长脑子吗，这都不会判，活着干嘛 
*/
#include<bits/stdc++.h>
#define Hahaha using
#define I namespace
#define AK std
#define IOI ;
#define ll long long
#define N (int)(1e5 + 10)
Hahaha I AK IOI

void work(){
	string a1, a2, b1, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	if(a1 != a2){
		cout << "0000";
		return;
	}
	string n1, n2;
	n1 = b1.substr(0, 2);
	n2 = b2.substr(0, 2);
	if(n1 != n2){
		cout << "1000";
		return;
	}
	if(b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C'){
		if(!(b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C')){
			cout << "1100";
			return;
		}
		int x1 = b1[2] - 'A', x2 = b2[2] - 'A';
		if(abs(x1 - x2) == 1){
			cout << "1111";
		}else{
			cout << "1110";
		}
	}else{
		if(!(b2[2] == 'D' || b2[2] == 'F')){
			cout << "1100";
			return;
		}
		cout << "1111";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int oT_To = 1;
//	cin >> oT_To;
	while(oT_To--){
		work();
	}
	return 0;
}
