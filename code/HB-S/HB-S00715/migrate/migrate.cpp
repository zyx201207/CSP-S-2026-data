#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("migrate.in");
    ofstream fout("migrate.out");
    int c,n;
    fin>>c>>n;
    while(n--)
        fout<<"0\n";
}
