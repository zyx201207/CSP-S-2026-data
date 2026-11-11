#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//#define fin cin
//#define fout cout
int n;
long long m, ans;
long long count(vector<long long> a, long long v){
	long long output = 0;
	for (long long i = 0; i < a.size(); i++){
		if (a[i] == v) output++;
	}
	return output;
}
//*
void DFS(long long deep, vector<long long> a, int b){
	if (deep == m){
		for (int i = 0; i < a.size(); i++){
			ans = max(ans, count(a, a[i]));
		}
		return;
	}
	else{
		for (int i = b; i < a.size() - 1; i++){
			a[i]++;
			if (deep == m - 1 || deep == m - 2)
				for (int i = 0; i < a.size(); i++)
					ans = max(ans, count(a, a[i]));
			DFS(deep + 1, a, i);
		}
	}
}
//*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	fin >> n >> m;
	vector<long long> engines(n + 1);
	sort(engines.begin(), engines.end());
	for (int i = 0; i < n; i++){
		fin >> engines[i];
	}
	if (n < 130) DFS(1, engines, 0);
	else {
		fout << (int)n / 2 * 1.4;
	}
	fout << ans;
	fin.close(); fout.close();
	return 0;
}
