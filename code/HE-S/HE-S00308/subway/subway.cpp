#include<bits/stdc++.h>
using namespace std;
const int N=2e4+33;
int c,n,m,d,q;
int w[N],k[N],t[510][N];
vector<int>g[N];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int a[N];
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int x=j+1;x<=k[i];x++){
				g[j].push_back()
			}
		}
	}
	return 0;
}
