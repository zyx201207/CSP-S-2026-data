#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream seed_in("seed.txt");
    int seed;
    seed_in >> seed;
    seed_in.close();
    mt19937 rnd(seed);

	int n = rnd() % 10 + 11;
	cout << n << '\n';
    for(int i = 1; i <= n; i++)cout << rnd() % (1 << 30) << ' ';

    ofstream seed_out("seed.txt");
    seed_out << seed + 2;
    seed_out.close();
    return 0;
}
