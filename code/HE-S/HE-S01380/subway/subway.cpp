#include<bits/stdc++.h>
using namespace std;
long long w[10001],z[10001][10001],t[10001][10001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long q,a,b,c,d,m,n;
	cin>>q>>a>>b>>c>>d;
	for(int i=1;i<=b;i++){
		cin>>w[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			cin>>z[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=d;i++){
		cin>>m>>n;
	}
	while(d>0){
		
		
		
		d--;
	}
	return 0;
}
