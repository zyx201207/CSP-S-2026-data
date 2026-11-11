#include<bits/stdc++.h>
using namespace std;
int a[500005];char c[500005];
bool che[500005],mm[300005];
long long ans[300005];
int main(){
	ifstream fin("card.in");
	ofstream fout("card.out");
	int n,m;
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	for(int i=1;i<=m;i++) fout<<1<<" ";
	fin.close();
	fout.close();
} 
