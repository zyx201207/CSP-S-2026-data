#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//#define fin cin
//#define fout cout
int n, m;
long long ans, and_ans;
string s;
int main(){
	fstream fin("and.in");
	fstream fout("and.out");
	fin >> n >> m;
	vector<int> l(n + 1);
//	vector<int> l_max(m + 1);
	for (int i = 0; i < n; i++) fin >> l[i];
	/*
	if (m == 2){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				and_ans = l[i] & l[j];
				ans = max(ans, and_ans);
			}
		}
	}
	else if (m == 3){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					and_ans = l[i] & l[j] & l[k];
					ans = max(ans, and_ans);
				}
			}
		}
	}
	*/
//	for (int i = 0; i < n; i++){
//		s = "";
//		int cpy = l[i];
//		while (cpy){
//			s = (char(cpy % m)) + s;
//		}
//		l_max[i] = s.count('1');
//	}
//	for (int i = 0; i < m; i++){
//		ans += *max_element(l_max);
//		max_element(l_max) = 0;
//	}
//	
	
	sort(&l[0], &l[n]);
	fout << l[n / 2 + n % 2 - 1]; 
	
	
	
//	fout << ans;
	fin.close(); fout.close();
	return 0;
}
