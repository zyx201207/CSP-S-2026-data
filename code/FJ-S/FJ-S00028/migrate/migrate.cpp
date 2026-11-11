#include<bits/stdc++.h>
using namespace std;
int x[2000001];
int main(){
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n , c , t ,d;
	cin >>c>>t;
	for(int i =1 ; i <= t ; i++){
		cin>>n>>d;
		for(int j =1 ; j <= n ; j++)
			cin>>x[i];
			int k = x[2]-x[1];
			int kk = d/k;
			cout << n-kk+1; 
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
