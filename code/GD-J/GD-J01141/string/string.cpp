#include <bits/stdc++.h>
using namespace std;
long long sum;
string a;
int w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> w;
	int u;
	char q;
	for(int i=1;i<=w;i++){
		cin >> u;
		cin >> q;
		for(int j=1;j<=u;j++){
			a += q;
		}
	}
	 
	int l = a.size();
	for(int i=0;i<=l/2-1;i++){
		if(a[i] != a[l - i-1]){
			sum++;
		}
		
	}
	cout << sum;
	
	
	
	
	
	
	return 0;
} 
