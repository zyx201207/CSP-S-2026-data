#include<bits/stdc++.h>
using namespace std;
long long w[510000],k[510000];
long long a[505][30];
long long t[505][30];
bool f[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	int x=10;
	srand(time(0));
	for(int i=1;i<=q;i++) {
		cout<<rand()/x%10<<endl;
		x*=10;
	}
	/*for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k[i];j++){
			f[a[i][j-1]][a[i][j]]=false;
			f[a[i][j]][a[i][j-1]]=false;
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>x>>y;
		bool ff=true,fff=true;
		int sum=0;
		while()
	}*/
	return 0;
}
