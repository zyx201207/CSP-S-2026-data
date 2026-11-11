#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ofstream fout("check.out");
	int cnt=0;
	while(1){
		system("data.exe");
		system("baoli.exe");
		system("and.exe");
		if(system("fc and.out baoli.out > nul")){
			cout<<"WA"<<++cnt<<"\n";
			fout<<"WA"<<cnt<<"\n";
		}
		cout<<"AC"<<++cnt<<"\n";
		fout<<"AC"<<cnt<<"\n";
	} 
	return 0;
}
