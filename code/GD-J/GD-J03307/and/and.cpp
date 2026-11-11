#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,max = 0,ii,jj;
	cin >> n >> m;
	long long a[n+5];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	long long i = 0,j = 0;
	for(i = 0;i < n;i++){
		for(j = i+1;j < n-1;j++){
			if((a[i] & a[j]) > max){
				max = (a[i] & a[j]);
				ii = i;
				jj = j;
			}
		}
	}
	a[ii] = 0;
	a[jj] = 0;
	while(m > 2){
		
		long long t = 0;
		for(i = 0;i < n;i++){
			if((max & a[i]) > t){
				t = (max & a[i]);
				cout << a[i] << " " << t << endl;
				ii = i;
			}
		} 
		max = t;
		a[ii] = 0;
		m--;
	}
	cout << max;
	
	return 0;
	//Trick||Treat!
}
