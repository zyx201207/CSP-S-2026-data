#include <bits/stdc++.h>
#include <windows.h>
using namespace std;


int main() {
	string s = "crystal";
	for (int i = 1; i <= 5; i++) {
		string s1 = s + char(i + '0');
		system(("copy " + s1 + ".in " + s + ".in").c_str());
		system((s + ".exe").c_str());
		system(("fc " + s1 + ".ans " + s + ".out").c_str());
	}
} 
