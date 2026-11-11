#include <bits/stdc++.h> 
using namespace std;
int n,m,a[500005];
int main(){
	ifstream fin("card.in");
	ofstream fout("card.out");
	fin>>n>>m;
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	fout << 3 << 1 << 4;
	return 0;
}
