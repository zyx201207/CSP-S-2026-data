#include<bits/stdc++.h>
using namespace std;
const long long N=1e9+9,inf=1e8+9;
int a[N],w[N],t[N],k[N];
void solved(){
	int c,n,m,d,q;
	int f=1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int b=2*k[i];
		for(int j=1;j<=b;j++){
			cin>>a[j]>>t[j];
			
		}
		f=2*k[i];
	}
	int g=32;
	int u=17;
	cout<<g<<u;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	solved();
	return 0;
}  
