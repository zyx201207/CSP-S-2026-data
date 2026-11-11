#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> card,desktop,ans;
vector<bool> stat;
int a,n,m;
int main(){
	ifstream fin("card.in");
	ofstream fout("card.out");
	fin >> n >> m;
	stat.resize(m,0);
	ans.resize(m,0);
	for(int i=0;i<n;i++){
		fin >> a;
		card.push_back(a);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(desktop.empty()||!stat[card[j]-1]){
				desktop.push_back(card[j]);
				stat[card[j]-1]=1;
			}else if(stat[card[j]-1]){
				stat[desktop.back()-1]=0;
				desktop.pop_back();
				j--;
			}
		}
		while(!desktop.empty()){
			ans[desktop.back()-1]++;
			stat[desktop.back()-1]=0;
			desktop.pop_back();
		}
	}
	for(long ks:ans){
		fout << ks << " \0";
	}
	fin.close();
	fout.close();
	return 0;
}
