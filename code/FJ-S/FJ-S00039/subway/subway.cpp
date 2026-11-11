#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1919810];//hyw,Where is the "M"'s fanwei?
int k[505];
int a[505][500005];
int t[505][500005];
int x[100005];
int y[100005];
bool check[1919810];
int v[1919810];
queue <int> que;

int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		
		while(!q_s.empty())q_s.pop();
	}
	return 0;
}
//Oct31==Dec25?
