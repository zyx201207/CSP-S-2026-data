#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n[N], d[N], x[N][N], f[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin>>c>>t;
	for(int i=0; i<t; i++){
		cin>>n[i]>>d[i];
		for(int j=0; j<n[i]; i++){
			cin>>x[i][j];
		}
		for(int p=0; p<n[i]-3; p++){
			if(x[p+3]-x[p]==3){
				f[i]++;
			}
		}
	}
	for(int i=0; i<t; i++){
		cout<<f[i]<<endl;
	}
	return 0;
}
