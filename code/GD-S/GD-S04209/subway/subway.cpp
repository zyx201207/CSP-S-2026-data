#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=5e5+5;
int c,n,m,d,q,w[M],a[N][N];
unordered_map<int,int> t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=0,r;i<n;i++){
		cin >> r;
		for(int j=0,x,y;j<r;j++){
			cin >> x >> y;
			t[x][i]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j=t[i].begin();j!=t[i].end();j++){
			auto k=j;
			k++;
			for(;k!=t[i].end();k++){
				if(!a[j->first][k->first]||a[j->first][k->first]>j->second+k->second){
					a[j->first][k->first]=a[k->first][j->first]=j->second+k->second;
				}
			}
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i][k]&&a[k][j]&&(!a[i][j]||a[i][j]>a[i][k]+a[k][j])){
					a[i][j]=a[j][i]=a[i][k]+a[k][j];
				}
			}
		}
	}
	for(int i=0,x,y,ans=0;i<q;i++,ans=0){
		cin >> x >> y;
		for(auto j=t[x].begin();j!=t[x].end();j++){
			for(auto k=t[y].begin();k!=t[y].end();k++){
				if(!ans||ans>j->second+k->second+a[j->first][k->first]){
					ans=j->second+k->second+a[j->first][k->first];
				}
			}
		}
		cout << w[x]+w[y]+ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
}
