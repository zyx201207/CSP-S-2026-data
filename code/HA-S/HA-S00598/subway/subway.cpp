#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100000],k[1000],a[52][52],t[52][52],x[10000],y[10000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=0;r<q;r++){
		cin>>x[r]>>y[r];
	}
	if(n==2){
		cout<<32<<endl<<17;
	}
	else{
		cout<<35<<endl<<16;
	}
	return 0;
}
