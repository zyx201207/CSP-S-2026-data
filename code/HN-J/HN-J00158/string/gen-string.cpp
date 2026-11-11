#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream seed_in("seed.txt");
    int seed;
    seed_in >> seed;
    seed_in.close();
    mt19937 rnd(seed);

    int n = rnd() % 1000 + 1001;
    cout << n << '\n';
    for(int i = 1; i <= n; i++) {
    	int len = rnd() % 1000 + 1001;
    	char ch = rnd() % 26 + 'a';
    	cout << len << ' ' << ch << '\n';
	}

    ofstream seed_out("seed.txt");
    seed_out << seed + 2;
    seed_out.close();
    return 0;
}
