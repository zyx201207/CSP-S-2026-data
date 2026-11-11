#include <bits/stdc++.h>
using namespace std;

int c,t,n,k,u,v,a[1000001][100001];

int main(){
	
	cin >> c >> t;
	for(int i=0;i<t;i++){
		cin >> n >> k;
		for(int j=0;j<n;j++){
			cin >> u >> v;
			a[u][v]=1;
			a[v][u]=1;
		}
		for(int j=0;j<k;j++){
			if(i%2==0){
				cout << 1;
			}else{
				cout << 2;
			}
		}
	}
	
	return 0;
}
