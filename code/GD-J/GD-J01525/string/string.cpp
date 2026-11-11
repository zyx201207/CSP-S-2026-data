#include <iostream>
#include <vector>
using namespace std;
struct fc {
	int a;
	char c;
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	fc tem;
	tem.c = 0; tem.a = 0;
	vector <fc> v(n, tem);
	for (int i = 1, fe = 0; i <= n; i++) {
		int a; char c;
		cin >> a >> c;
		if ( !v.empty() && v[fe].c == c) {
			v[fe].a += a;
		}
		else {
			fc tem;
			tem.c = c;
			tem.a = a;
			v[fe] = tem;
			fe++;
		}
	}
	long long h = 0, t = 0, diff = 0;
	while (true) {
		fc* vh = &v[h], *vt = &v[v.size() - t - 1];
		int vha = vh->a, vta = vt->a;
		char vhc = vh->c, vtc = vt->c;
		if (vhc != vtc) {
			if (vha > vta) {
				diff += vta;
				vh->a = vta;
				fc tem;
				tem.a = vha - vta;
				tem.c = vhc;
				v.insert(v.begin() + h + 1, tem);
			}
			else if (vha < vta){ //vha < vta
				diff += vha;
				vt->a = vha;
				fc tem;
				tem.a = vta - vha;
				tem.c = vtc;
				v.insert(v.begin() + v.size() - t - 1, tem);
				//t++;
			}
			else {
				diff += vha;
			}
		}
		else {
			if (vha > vta) {
				vh->a = vta;
				fc tem;
				tem.a = vha - vta;
				tem.c = vhc;
				v.insert(v.begin() + h + 1, tem);
			}
			else if (vha < vta) { //vha < vta
				vt->a = vha;
				fc tem;
				tem.a = vta - vha;
				tem.c = vtc;
				v.insert(v.begin() + v.size() - t - 1, tem);
				//t++;
			}
		}
		int debug = 0;
		if (debug) {
			for (fc c : v) {
				cout << c.a << ' ' << c.c << endl;
			}
			cout << "h/t/diff/size: " << h << ' ' << t << ' ' << diff << ' ' << v.size() << endl << endl;
		
		}
		h++; t++;
		if (h + t + 1 >= v.size()) break;
	}
	cout << diff << endl;
}
