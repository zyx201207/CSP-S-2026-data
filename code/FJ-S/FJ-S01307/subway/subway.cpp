#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],a[505][500005],t[505][500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)  cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
		    cin>>a[i][j]>>t[i][j];
		}
	}
	 
	for(int i=1;i<=q;i++) cout<<rand()<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
