#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[505][450010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	long long x;
	for(int i=0;i<n;i++){
		cin>>x;
		b[i][0]=x;
		for(int j=1;j<=2*x;j++){
			cin>>b[i][j];
		}
	}
	long long y;
	for(int i=0;i<q;i++){
		cin>>x>>y;
		int sum=0;
		sum+=a[x];
		sum+=a[y];
		cout<<sum<<endl;
	}
	return 0;
} 
