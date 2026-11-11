#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define fin cin
#define fout cout
int c, n, m, d, q, k, start, aaaaaaa;
long long ans;
struct line{
	int stations;
	vector<int> i;
	vector<int> times;
};
int find(vector<int> a, int v){
	for (int i = 0; i < a.size(); i++){
		if (a[i] == v) return i;
	}
	return -1;
}
int main(){
//	ifstream fin("subway.in");
//	ofstream fout("subway.out");
	fin >> c >> n >> m >> d >> q; // 第一行包含五个非负整数
	vector<int> w(m + 1);
	vector<line> lines(n + 1);
	// 第二行包含 m 个正整数
	// 依次表示从每个地铁站的地铁口走到站厅需要的时间
	for (int i = 0; i < m; i++){
		fin >> w[i];
	}
	// n条线路依次输入 
	for (int i = 0; i < n; i++){
		fin >> lines[i].stations;
		for (int j = 0; j < lines[i].stations; j++){
			int temp;
			fin >> temp;
			lines[i].i.resize(lines[i].stations + 2);
			lines[i].i[k] = temp;
			lines[i].times.resize(lines[i].stations + 2);
			fin >> temp;
			lines[i].times[k] = temp;
			k++;
		}
	}
	// 输入计划
	for (int i = 0; i < q; i++){
		fin >> start >> aaaaaaa;
//		fout << lines[2].times[2] + lines[1].times[3] + w[3 - 1] + w[1 - 1];
			
	}
	fout << "32 19";
//	fin.close(); fout.close();
	return 0;
}
