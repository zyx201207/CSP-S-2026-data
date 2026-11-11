#include <bits/stdc++.h>
using namespace std;
int n[1000];
int maxn;
int sum;
int a,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> a >> b;
	for(int i=1;i<=a;i++){
		cin >> n[i];
	}
	if(b == a){
		sum = n[1];
		for(int i=2;i<=a;i++){
			sum = sum & n[i];
		}
		cout << sum;
	}
	else if(b == 1){
		for(int i=1;i<=a;i++){
			maxn = max(maxn,n[i]);
		}
		cout << maxn;
	}
	
	
	
	return 0;
} 
