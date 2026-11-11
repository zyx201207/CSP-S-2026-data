#include<bits/stdc++.h>
using namespace std;
int z[200002];
bool c(int a, int b){
	return a>b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>z[i];
	}
	sort(z, z+n, c);
	cout<<z[m-1];
	return 0;
}
