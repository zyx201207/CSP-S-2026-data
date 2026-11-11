#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int c,n,m,d,q,x,y;
long long w[MAX];
int k[MAX];
int a[205][MAX],t[205][MAX];
void ans(int st,int end){
		
}
int main(){
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
		ans(x[i],y[i]);
		
	}
} 
