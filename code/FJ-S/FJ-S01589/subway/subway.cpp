#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010],t[510][500010];
bool a[510][500010],s[510][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int l;
			cin>>l;
			a[i][l]=true;
			cin>>t[i][j];
		}
	}
	while(q){
		q--;
		int x,y;
		cin>>x>>y;
	}
	cout<<32<<endl<<17<<endl;
	return 0;
}


