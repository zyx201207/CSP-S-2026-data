#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream seed_in("seed.txt");
    int seed;
    seed_in >> seed;
    seed_in.close();
    mt19937 rnd(seed);

    cout << rnd();

    ofstream seed_out("seed.txt");
    seed_out << (rnd() << 3 ^ rnd() - rnd());
    seed_out.close();
    return 0;
}
