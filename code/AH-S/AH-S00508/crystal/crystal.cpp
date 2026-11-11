#include <bits/stdc++.h>

using namespace std;

const int N = 500000 + 100;

long long n,m;
long long l = 1,r = 0;
long long a[N] = {0};
long long c[N] = {0};
long long daan = 0;

bool cmp(long long x,long long y){
	return x < y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	sort(a + 1,a + n + 1,cmp);
	
	for(int i = 1;i <= n;i++){
		c[i] = a[i];
		a[i] = a[i] + a[i - 1];
	}
	
	while(r < n){
		r++;
		
		while(1){
			if((r - l + 1) * c[r] - (a[r] - a[l - 1]) <= m){
				daan = max(daan,r - l + 1);
				
				break;
			}
			
			l++;
		}
	}
	
	cout<<daan;
	
	return 0;
}
