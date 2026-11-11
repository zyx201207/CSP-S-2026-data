#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
//#define fin cin
//#define fout cout
int n, range_step;
long long head, tail, cnt;
struct s{
	int range;
	char c;
};
int main(){
	fstream fin("string.in");
	fstream fout("string.out");
	fin >> n;
	vector<s> ss(n + 1);
	for (int i = 0; i < n; i++){
		fin >> ss[i].range >> ss[i].c;
	}
	head = 0; tail = n - 1;
	while (head <= tail || ss[head].range > 0 && ss[tail].range > 0){
		range_step = min(ss[head].range, ss[tail].range);
		// 相等只减一次 
		if (head == tail) ss[head].range -= range_step;
		else {
			ss[head].range -= range_step;
			ss[tail].range -= range_step;
		}
		if (ss[head].c != ss[tail].c) cnt += range_step;
		if (ss[head].range == 0) head++;
		if (ss[tail].range == 0) tail--;
	}
	fout << cnt;
	fin.close(); fout.close();
	return 0;
}
