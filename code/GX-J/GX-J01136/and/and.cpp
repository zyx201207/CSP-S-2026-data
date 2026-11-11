#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin ("and.in");
    ofstream fout ("and.out");

    int a;
    int b;

    fin >> a;
    fin >> b;

    fin.close();
    fout.close();
    return 0;
}





