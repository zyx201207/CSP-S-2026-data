// /string/string.cpp

/*
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int inlen;
	string S;
	
	cin >> inlen;
	
	for (int i = 0;i < inlen;i ++){
		int a;
		char c;
		cin >> a >> c;
		for (int j = 0;j < a;j ++) S += c;
	}
	
	int times = 0;
	
	// 3(1) -> 1
	// 4(2) -> 2
	
	for (size_t i = 0;i < S.size()/2;i ++){
		// cout << "i: " << i << "  S.zise()-i: " << S.size()-i-1 << "\n";
		if (S[i] != S[S.size() - i - 1]){
			times ++;
		}
	}
	
	cout << times; //<< "\n" << S;
	 
	return 0;
} 

/*/

// 大数据待优化 
#include <iostream>
#include <string>
#include <fstream>
#include <utility> 
#include <vector>
using namespace std;

struct Range{
	int start;
	int end;
	char val;
	
	bool fit(int N) const {
		return start <= N && end > N;
	}
};

vector<Range> ranges;

int find_range(int n){
	for (size_t i = 0;i < ranges.size();i ++){
		int s = ranges[i].start;
		int e = ranges[i].end;
		if (s <= n && n <= e){
			return i;
		}
	}
	
	return -1;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int inlen, frontLen = 0;
	string S;
	
	cin >> inlen;
	
	for (int i = 0;i < inlen;i ++){
		int a;
		char c;
		cin >> a >> c;
		Range tmp;
		tmp.val = c;
		tmp.start = frontLen;
		frontLen += a;
		tmp.end = frontLen - 1;
		ranges.push_back(tmp);
	}
	
	long long times = 0;
	
	for (size_t i = 0;i < S.size()/2;i ++){
		int ano = S.size() - 1 - i;
		int iInd = find_range(i);
		int anoInd = find_range(ano);
		if (ranges[iInd].val != ranges[anoInd].val){
			times ++;
		}
	}
	
	cout << times;
	 
	return 0;
} 

// */
