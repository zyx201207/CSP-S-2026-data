#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int c,n,m,d,q,k;
int w[N],minn[510];
vector<int> g[510];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=500;i++)minn[i]=1e9;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>g[i][j];
			if(j%2==0)minn[g[i][j-1]]=min(minn[g[i][j-1]],g[i][j]);
		}	
	}
	int l,r;
	while(q--){
		cin>>l>>r;
		cout<<w[l]+w[r]+minn[l]+minn[r]<<endl;
	}
	return 0;
} 
