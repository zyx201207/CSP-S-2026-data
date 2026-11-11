#include <bits/stdc++.h>
using namespace std;
long long w[1010][1010];
vector <int> l[510];
vector <int> w2[1010];
bool w3[1010];
bool w4[1010]={true};
void f(int fu,int u,long long c){
	for (int i=0;i<w2[u].size();i++){
		int v=w2[u][i];
		long long cn=c+w[u][v];
		if (!w[fu][v]){
			w[fu][v]=cn;
			w[v][fu]=cn;
		}
		if (w3[v]||cn<w[fu][v]){
			w[fu][v]=min(w[fu][v],cn);
			w[v][fu]=min(cn,w[v][fu]);
			w3[v]=false;
			f(fu,w3[v],cn);
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)
		cin >> w[i][0];
	for (int i=0;i<n;i++){
		int k;
		cin >> k;
		for (int j=0;j<k;j++){
			int aj;
			cin >> aj;
			l[i].push_back(aj);
			for (int o=0;o<l[i].size();o++){
				if (w[aj][l[i][o]]<=0){
					w[aj][l[i][o]]=w[aj][0]+w[l[i][o]][0];
					w[l[i][o]][aj]=w[aj][0]+w[l[i][o]][0];
					w2[aj].push_back(l[i][o]);
					w2[l[i][o]].push_back(aj);
				}
				else{
					w[aj][l[i][o]]=min(w[aj][0]+w[l[i][o]][0],w[aj][l[i][o]]);
					w[l[i][o]][aj]=min(w[aj][0]+w[l[i][o]][0],w[l[i][o]][aj]);
				}
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++)
			w3[j]=true;
		f(i,i,0);
		for (int j=0;j<=m;j++)
			cout << w[i][j] << " ";
		cout << endl;
	}
	/*
	for (int i=0;i<q;i++){
		int x,y;
		cin >> x >> y;
		if (w4[x]){
			for (int j=1;j<=m;j++)
				w3[j]=true;
			f(x,x,0);
			w4[x]=false;
		}
		cout << w[x][y] << endl;
	}
	*/
	
	return 0;
}
