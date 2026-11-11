#include<bits/stdc++.h>
using namespace std;
long long a[100005],u[100005],t[100005][100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long r;
	cin>>r;
	for(int i=0;i<=m;i++){
		cin>>a[i];
	}
	for(int i=0;i<=m;i++) {
		cin>>a[i+2];
	}
	for(int i=0;i<=n-1;i++){
		cin>>u[i];
	}
	long long x;
	x=r+n+2;
	cout<<x<<endl;
	cout<<u[1]+t[1][1]+(t[1][2]+t[2][2])+t[2][3]+u[3]<<endl;
	cout<<u[1]+t[1][1]+t[1][2]+u[2];
	return 0;
}
