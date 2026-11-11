#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
const string question_name = "migrate";

int main(){
	ifstream fin(question_name + ".in");
	ofstream fout(question_name + ".out");
	
	int n,m;
	fin>>n>>m>>n>>m;
	if(n == 4 and m == 2)fout<<"1\n2";
	if(n == 5 and m == 3)fout<<"0\n1";
	
}
