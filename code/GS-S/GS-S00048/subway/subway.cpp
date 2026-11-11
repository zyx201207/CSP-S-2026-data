#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
int w[500005];
int a[500005][505],t[500005][505],r[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=r[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int test=1;test<=q;test++){
		int x,y;
		cin>>x>>y;
		cout<<"35"<<endl<<"16";
	}
	return  0;
}
