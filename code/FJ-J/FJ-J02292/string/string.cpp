#include <bits/stdc++.h>
using namespace std;

long long n, i, l, r; 
long long sum = 0, diff = 0, m, p1 = 0, p2 = 0;
long long a[210000];
char b[210000];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin>>n;
	for(i = 0;i<n;++i){
		cin>>l>>b[i];
		a[i] = l;
		sum += l;
	}
	l = 0;
	r = n-1;
	while(1){
		if(l > r){
			break;
		}
		m = min(a[l]-p1, a[r]-p2);
		p1 += m;
		p2+=m;
		if(b[l] != b[r]){
			diff += m;
		}
		if(p1 >= a[l]){
			p1=0;
			++l;
		}
		if(p2 >= a[r]){
			p2=0;
			--r;
		}
	}
	cout<<diff;
	
	return 0;
}
