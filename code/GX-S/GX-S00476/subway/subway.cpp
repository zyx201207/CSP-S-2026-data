#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int w[500005],n,m,q,x[100003],y[100003],c,d,k[502],a[502][500005],t[502][500005],vis[502];
vector<int>l[502];
int main(){
	fstream fin,fout;
	fin.open("subway.in");
	fout.open("subway.out");
	fin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		fin>>w[i];
	}
	for(int i=1;i<=n;i++){
		fin>>k[i];
		for(int j=1;j<=k[i];j++){
			fin>>a[i][j]>>t[i][j];
			l[i].push_back(a[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		fin>>x[i]>>y[i];
		/*queue<int>li;
		li.push(1);
		vis[1]=1;
		while(li.size()){
			int x=li.front();
			for(int i=0;;break);
		}*/
		fout<<w[x[i]]+w[y[i]]+t[1][1]+t[n][1]+t[1][k[1]]<<endl;
	}
	return 0;
}
