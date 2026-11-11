#include <bits/stdc++.h> 
using namespace std;

int sum[500];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "W", stdout);
	int n, m, l[25];
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>l[i];
	}
	int t=0;
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			sum[l[i]&l[j]]++;
		}
	}
	for(int i=0; i<=500; i++){
		if(sum[i]==m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
