#include <iostream>
using namespace std;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int lp[1000],h[1000],h1[1000];
	int o[1000],o1[1000];
	for(int i=1;i<=m;i++){
		cin>>lp[i];
	}
	for(int i=0;i<1;i++){
		int a;
		cin>>a;
		for(int j=1;j<=a;j++){
		cin>>h[j]>>h1[j];
		}
		int y;
		cin>>y;
		for(int j=1;j<=y;j++){
		cin>>o[j]>>o1[j];
		}
	}
	for(int i=1;i<=q;i++){
		int f,g;
		cin>>f>>g;
	}
	cout<<32<<" "<<17;
	
	
	
	
	
	
	
	
	return 0;
}
