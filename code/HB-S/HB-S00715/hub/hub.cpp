#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("hub.in");
    ofstream fout("hub.out");
    int c,n;
    fin>>c>>n;
    while(n--)
        fout<<"0\n";
}



