#include <bits/stdc++.h> 

using namespace std;

int a[1001];

int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	int n,m;
	cin >>n>>m;
	
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	
	
	int mb=10000,mn;
	int mx=0;
	
	while(m){
		
		sort(a,a+n);
		
		a[1]++;
		int b[1001]{};
		
		for(int i=1;i<=n;i++){
			b[a[i]]++;
			mx=max(b[a[i]],mx);
		}
		m--;
	}
	
	
	cout <<mx;
	return 0;
};


