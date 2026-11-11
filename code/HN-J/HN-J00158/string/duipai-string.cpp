#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	do{
		system("gen-string > data.in");
		system("string-bf < data.in > bf.out");
		system("string-std < data.in > std.out");
	}while(!system("fc bf.out std.out"));
	system("msg * \"¶ÔÅÄ string Ê§°Ü\""); 
    return 0;
}
