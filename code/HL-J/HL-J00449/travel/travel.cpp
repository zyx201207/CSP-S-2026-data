#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2 ;
	if(c1 != c2){
		cout << "0000" << '\n';
		return 0;
		//是否同一车厢 
	}else{
		cout << "1"; 
		int seat1=(s1[0]-'0')*10+s1[1]-'0';
		int seat2=(s2[0]-'0')*10+s2[1]-'0';
		//同一排 
		if(seat1 == seat2){
			cout << "1";
		}else{
			cout << "000";
			return 0; 
		}
		//同一侧 
		char a=s1[2],b=s2[2];
		bool isa = ((a == 'A' || a == 'B') || a == 'C') ? 1 : 0;
		bool isb = ((b == 'A' || b == 'B') || b == 'C') ? 1 : 0;
		bool isans = (isa == isb);
		if(isans){
			cout << "1" ;
		}else{
			cout << "00";
			return 0;
		}
		//座位相邻 
		if(isa == 0 && isb == 0){
			cout << "1";
			return 0;
		}else{
			if(a == 'B' || b == 'B'){
				cout << "1";
				return 0;
			}else{
				cout << "0";
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
