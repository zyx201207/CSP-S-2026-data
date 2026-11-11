#include <fstream>
#include <vector>
static char ib[1 << 20], ob[1 << 20];
int n, ai, L=0;
char ci;
long long cost=0;
struct Sub {
	long long start;
	int a;
	char c;
};
Sub str[(int)1e5]; 
long long mirrSub(int i) {
	long long res;
	for (int j=n-1;j>=0;j--) {
		if (str[j].start < (L-1)/2) break;
		if (L-str[i].start-1 >= str[j].start+str[j].a-1) {
			if (L-str[i].start-str[i].a <= str[j].start) {
				if (str[i].c != str[j].c) res += str[j].a;
			} else {
				if (str[i].c != str[j].c) res += str[j].start+str[j].a - L-str[i].start-str[i].a;
			}
		} else {
			if (L-str[i].start-str[i].a > str[j].start) {
				if (str[i].c != str[j].c) res += str[i].a;
			} else {
				if (str[i].c != str[j].c) res += L-str[i].start - str[j].start;
			}
		}
	}
	return res;
}
int main() {
	std::ifstream fin; fin.rdbuf()->pubsetbuf(ib, 1 << 20); fin.open("string.in");
	std::ofstream fout; fout.rdbuf()->pubsetbuf(ob, 1 << 20); fout.open("string.out");
	fin >> n;
	fin >> ai >> ci;
	str[0].start=0; str[0].a=ai; str[0].c=ci;
	for (int i=1;i<n;i++) {
		fin >> ai >> ci;
		str[i].start=str[i-1].start+str[i-1].a; str[i].a=ai;str[i].c=ci;
		L += ai;
	}
	for (int i=0;i<n;i++) {
		if (str[i].start+str[i].a-1 > (L-1)/2) break;
		cost += mirrSub(i);
	}
	fout << cost;
	return 0;
}
