#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	char code;
	//±àºÅ 
	int num;
	//¸öÊý 
};
node str[100096];
signed main(){
	ifstream fin("string.in");
	ofstream fout("string.out");
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	int n;
//	cin >> n;
	fin >> n;
	int totLen = 0;
	for(int i = 1;i <= n;i++){
		int num;
//		cin >> num;
		fin >> num;
		char c;
//		cin >> c;
		fin >> c;
		totLen += num;
		str[i].code = c;
		str[i].num = num; 
	}
	int res = 0;
	node last = str[1]; 
//	cout << last.code << " " << last.num << " \n";
	for(int i = 1,j = n;i <= j; ){
		int dir = last.num - str[j].num;
//		cout << dir << " ";
		if(dir > 0){
			if(last.code != str[j].code){
				res += str[j].num; 
			} 
			last.num = abs(dir);
			j--;
		}else if(dir < 0){
			if(last.code != str[j].code){
				res += last.num; 
			} 
			last.code = str[j].code;
			last.num = abs(dir);
			i++;
		}else{
//			cout << " gone \n";
			if(last.code != str[j].code){
				res += last.num; 
			} 
			last.num = str[i + 1].num;
			last.code = str[i + 1].code;
//			cout << "lastNum " << last.num << " ";
//			cout << "lastCode " << last.code << " ";
			i++;
			j--;
		}
	}
//	cout << res << "\n";
	fout << res << "\n";
	return 0;
} 
/*
3
 2 a
 2 b
 1 c
*/
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/ /*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 a
1000000000 a
1000000000 a
*/ 

