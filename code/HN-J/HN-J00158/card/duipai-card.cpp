#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	do{
		system("gen-card > data.in");
		system("card-bf < data.in > bf.out");
		system("card-std < data.in > std.out");
	}while(!system("fc bf.out std.out"));
	system("msg * \"╤тед card й╖╟э\""); 
    return 0;
}
