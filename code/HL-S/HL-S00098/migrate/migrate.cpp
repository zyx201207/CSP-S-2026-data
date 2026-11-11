#include<bits/stdc++.h>
using namespace std;
int c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n=0,d=0;
		int x[2100];
		struct P{
			int qian;
			int hou;
		}xn[2100];
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=2;j<n;j++){
			xn[j].qian=x[j]-x[1];
			xn[j].hou=x[n]-x[j];
			cout<<xn[j].qian<<' '<<xn[j].hou<<endl;
		}
	}
	return 0;
}
