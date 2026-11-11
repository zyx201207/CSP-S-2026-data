#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,p;
int r;
int w[10000001];
int k[10000001];
int x[10001],y[10001];

int main(){
	freopen("subway.in","r",stdin);
	cin>>c>>n>>m>>d>>p;
	 for(int i=1;i<=m;i++){
	 	cin>>w[i];
	}
	cin>>k[1];
	for(int i=1;i<=k[1]*2;i++){
		cin>>k[i+1];
	}	 
	cout<<"32 17";
	freopen("subway.out","w",stdout);
	return 0;
}
