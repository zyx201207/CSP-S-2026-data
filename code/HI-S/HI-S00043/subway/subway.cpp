#include<bits/stdc++.h>
using namespace std;
const int M=5E5+10;
int w[M];
int main(){
	ios::sync_with_stdio(0);
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	int c,n,m,d,q,x,y;
	fin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		fin>>w[i];
	for(int i=1;i<=n;i++){
		int k,tmp;fin>>k;
		for(int j=1;j<=2*k;j++)
			fin>>tmp;
	}fin>>x>>y;
	fout<<w[x]+w[y];
	return 0;
}

