#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;

long long all[maxn];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	
	for(int k = 0;k < c;k++){
		int n,d;
		cin >> n >> d;
		int A,A1;
		for(int i = 0;i < n;i++){
			cin >> all[i];
			if(i == 1){
			  A = all[1] - all[0];
			  A1 = A;
			  }
			  if(i > 2){
			  	A1 = all[i] - all[i - 1];
			  }
			}
		if(A==A1){
		  if(d <= 2*A){
		  	cout <<"0"<< endl;
		  	continue;
		  }	
		  if(d > 2*A){
		  	int A2 = d/A;
		  	cout << n - A2 - 1 << endl;
		  	continue;
		  }
		}
		  cout <<"0" <<endl; 
		}
		return 0;
	}
	
	
