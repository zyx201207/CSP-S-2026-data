#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	do{
		system("gen-and > data.in");
		system("and-bf < data.in > bf.out");
		system("and-std < data.in > std.out");
	}while(!system("fc bf.out std.out"));
	system("msg * \"¶ÔÅÄ and Ê§°Ü\""); 
    return 0;
}
