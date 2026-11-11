#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<int> list;
	ifstream fin("and.in");
	ofstream fout("and.out");
	int n,m,k,ans=0,cnt;
	fin >> n >> m;
	while(n--){
		fin >> k;
		list.push_back(k);
	}
	sort(list.begin(),list.end(),less<int>());
	for(int j=0;j<list.size();j++)
		for(int i=j+1;i<list.size();i++)
			ans=max(ans,list[i]&list[j]);
	fout << ans;
	return 0;
}/*
4 2
3 15 12 12
*/
