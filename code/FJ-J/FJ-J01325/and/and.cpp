#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[200005],b[200005];


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i ++){
		cin >> a[i];
	}				
	sort(a + 1, a + 1 + n);
	if(m == 1){
		cout << a[n];
		return 0;
	}
	if(m == 2 && n <= 2000){
		int maxx = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				if((a[i] & a[j]) >= maxx) maxx = a[i] & a[j];
			}
		}
		cout << maxx;
		return 0;
	}
	long long i = 1;
	while(m > 0){
		if(i == 1 || b[i - 1] != a[n]){
			b[i ++] = a[n --];
			m --;
		} 
		else{
			n --;
		}
	}
	i --;
	long long ans = b[1] & b[2];
	for(long long k = 3; k <= i; k ++){
		ans = ans & b[k];
	}
	cout << ans;
	return 0;
}	
