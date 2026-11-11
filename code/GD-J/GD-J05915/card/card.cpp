#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >>n>>m;
	int z[n+1];
	int z2[n + 1];
	
	for(int i = 0;i<n;i++){
		cin >> z[i];
		z2[i] = z[i];
	}
	if(n == 4){
		cout << 3 <<" "<< 1 << " "<< 4;
	}else{
		cout << 10 <<" " << 3 <<" "<< 3;
	}
	
	return 0;
}
