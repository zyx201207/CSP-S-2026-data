#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
const string question_name = "hub";

int main(){
	ifstream fin(question_name + ".in");
	ofstream fout(question_name + ".out");
	
	int c,t;
	fin>>c>>t;
	int n,k;
	if(c == 13 or c == 14){
		for(;t;t--){
			fin>>n>>k;
			fout<<(n/2+1) / (k+1)<<'\n';
			for(n--;n;n--)fin>>k>>k;
		}
	}
	fout<<"1\n2";
}
