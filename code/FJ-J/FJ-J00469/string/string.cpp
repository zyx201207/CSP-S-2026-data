#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int a[2*100000+5];
char b[2*100000+5];
long long ans, w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		long long u;
		cin >> u;
		a[i] = u;
		w += u;
		char h;
		cin >> h;
		b[i] = h;/*
		for(long long j = 1; j <= u; j++){
			s += h;
		}*/
	}
	//long long w= s.size();
	int l = 1, r = n;
	while(l<r){
		if(b[l] != b[r]){
			long long k = min(a[l],a[r]);
			ans += k;
			if(a[l] < a[r]){
				l++; a[r] -= k;
			}else
				if(a[l] > a[r]){
					r--; a[l] -= k;
				}else{
					l++; r--;
				}
		}else{
			long long k = min(a[l],a[r]);
			
			if(a[l] < a[r]){
				l++; a[r] -= k;
			}else
				if(a[l] > a[r]){
					r--; a[l] -= k;
				}else{
					l++; r--;
				}
		}
	}
	cout << ans;
	return 0;
} 
