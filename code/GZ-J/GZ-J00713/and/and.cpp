//GZ-J00713 遵义市新蒲中学 朱若鸣 
#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main(){
	int n,m;
	ifstream fin;
	fin.open("and.in");
	ofstream fout;
	fout.open("and.out");
	fin>>n>>m;
	for(int i=0;i<n&&i<100000000;i++) fin>>a[i];
	sort(a,a+n);
	int cmax=a[n-1];
	for(int i=0;i<m;i++) {
		cmax&=a[n-1-i];
	}
	fout<<cmax;
	return 0;
}
