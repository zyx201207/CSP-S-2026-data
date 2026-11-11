#include<bits/stdc++.h> 
using namespace std;
int i,j = 0,n,sum = 0,num = 0;
int a[500010] = {},b[500010] = {};
long long m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(i = n-1; i > 0; i--){
		long long ms = m;
		for(j = 0; j <= i; j++){
			long long b = a[i] - a[j];
			if(b <= ms){
				ms -= b;
				sum++;
			}
			
		}
		num = max(num,sum);
		sum = 0;
	}
	cout << num;
	return 0;
}
