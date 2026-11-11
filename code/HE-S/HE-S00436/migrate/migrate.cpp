#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000009];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int f[1400][1400];//表示从i-j的最短路径的次数 
	for(int l=1;l*l<=n;l++){
		if(x[l+1]-x[l]>d) continue;
		for(int r=n;r>=sqrt(n);r--){
//			int dep=0;
//			int i=l;
//			while(i<r){
//				i+=d/(x[i+1]-x[i]);
//				dep++;
//			}
		}
	}
	return 0;
}
