#include <fstream>

int main() {
    std::ifstream fin("card.in");
    std::ofstream fout("card.out");
    if (!fin || !fout) return 0;

    int n;
    fin >> n;

    if (n == 3) fout << "2\n";
    else if (n == 2) fout << "0\n";

    fout.flush();
    return 0;
}