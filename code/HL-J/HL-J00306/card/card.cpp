#include <bits/stdc++.h>
using namespace std;

int a[500005];
int b[500005];
int cnt[500005];
int i = 0, i2 = 0;
int main(){
	freopen("travel.in", "r",stdin);
	freopen("travel.out", "w",stdout);
	int n,m;
	cin >> n >> m;
	int ti = n;
	for(int i = 0; i < n ;i++){
		cin >> a[i];
	}
	while(ti = 0){	
		while(ti = 0){
			b[i] = a[i2];
			for(int j = 0;j < i; j++){
				if(b[j] == b[i]){
					for(int k = 0;k < i; k++){
						b[k] == 0;
					}
					b[0] = a[i2];
					i = 1;
				}
			}
			i++;
			i2++;
			ti--;
		}
		ti = n;
		for(int d = 0; d < i; d++){
			cnt[b[d]]++;
			ti--;
			}
		}
	for(int c = 0;c <= m;c++){
		if(cnt[c] != 0){
			cout << cnt[c];
		}
	}
	return 0; 
}