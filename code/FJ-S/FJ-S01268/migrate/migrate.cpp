#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,a,b;
	cin>>c>>t;
	int x[100001][2000000];
	for(int i=0;i<t;i++){
		int n[t],d[t];
		cin>>n[i]>>d[i];
		for(int j=0;j<n[i];j++){
			cin>>x[i][j];
		}
	}
	cout<<a<<endl<<b;
	return 0;
}
//1		1		-2		-4
//2		2		-1		-3
//3		3		0		-2
//4		4		1		-1
//		5		2		3
//		 				6
