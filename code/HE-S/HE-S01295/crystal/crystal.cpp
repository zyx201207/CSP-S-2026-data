#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
long long b[10000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal,out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 1; i < n; i++){
		b[i] = a[i] - a[i - 1];
	}
	long long sum = 0;
	int mx = 1;
	int x = 1;
	for(int i = n - 1 ; i >= 1; i--){
		sum = 0;
		x = 1;
		for(int j =i; j >= 1; j--){
			if(sum * 2 + b[j] > m){
				if(x > mx){
					mx = x;
				}
				break;	
			}
			sum = sum * 2 + b[j];
			x++;
			if(j == 1){
				if(mx < x){
					mx = x;
				}
			} 
		}
		
	}
	cout<< mx;
	return 0;
}
