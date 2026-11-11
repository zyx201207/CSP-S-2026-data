#include <bits/stdc++.h> 

using namespace std;

int a[1001];

int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	int c,t;
	cin >>c>>t;
	
	int n,d;
	
	while(t--){
		cin >>n>>d;
		for (int i=0;i<n;i++){
			cin >>a[i];
		}
	}
	
	
	return 0;
};


