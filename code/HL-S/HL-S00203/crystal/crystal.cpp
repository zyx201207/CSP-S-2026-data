/*
#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	int n,m=0;
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	
	fout<<m; 
	fin.close();
	fout.close();
	return 0;
} 
*/
#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	int n,m;
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	for(int x=1;x<=m;x++){
		int sum=0;
		for(int i=1;i<=m;i++){
			if(a[x]+1==a[i]){
				sum++;
			} 
		}
	}
	fout<<sum;
	fin.close();
	fout.close();
	return 0;
} 
