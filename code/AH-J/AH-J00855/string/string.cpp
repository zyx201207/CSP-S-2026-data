#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 100;

long long n;
long long sss;
long long l,r;
long long a[N] = {0};
long long ans = 0;
char b[N] = {0};

long long MIN(long long x,long long y){
	if(x < y){
		return x;
	}
	return y;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}
	
	l = 1,r = n;
	
	while(l < r){
		sss = MIN(a[l],a[r]);
		
		if(b[l] != b[r]){
			ans = ans + sss;
		}
		
		a[l] = a[l] - sss;
		a[r] = a[r] - sss;
		
		if(a[l] == 0){
			l++;
		}
		if(a[r] == 0){
			r--;
		}
	}
	
	cout<<ans;
	
	return 0;
}
