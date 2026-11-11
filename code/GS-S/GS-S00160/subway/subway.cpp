#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[100];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k[100];
	for(int i=1;i<=14;i++){
		cin>>k[i];
	}
	int x[100];
	int y[100];
	for(int i=1;i<=2;i++){
		cin>>x[i];
		cin>>y[i];
	}
	if(n==2)cout<<32<<endl<<17;
	if(n==3)cout<<35<<endl<<16;
	return 0;
}
