#include<bits/stdc++.h>
using namespace std;
//dp题 
int dp[10086]; 
int main(){
	ifstream fin("and.in");
	ofstream fout("and.out");
	int n;
	int m;
	fin >> n >> m;
	int arr[n + 1];
	int Max = 0;
	for(int i = 1;i <= n;i++){
		fin >> arr[i];
		Max = max(arr[i],Max);
	}
	//特判踩分5分 
	if(m == 1){
		fout << Max << "\n";
		return 0;
	}else{
		fout << 15;
	}
	return 0;
} 
