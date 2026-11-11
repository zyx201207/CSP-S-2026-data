#include<bits/stdc++.h>
using namespace std;
int a[500010], b[500010], s[500010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int p = 1;p <= n;p++){
		for(int i = p;i<= n;i++){
			for(int j = p;j < i;j++){
				int tmp = b[i];
				if(b[i] == b[j]){
					for(int f = j;f <= i;f++){
						b[f] = 0;
					}
					b[j] = tmp;
				}
			}
		}
		for(int i = p;i <= n;i++){
			s[b[i]]++;
		}
		for(int i = 1;i <= n;i++){
			b[i] = a[i];
		}
	}
	if(m % 2 != 0){
		s[1]++;
		s[m]++;
	}else{
		s[1]++;
	}
	for(int i = 1;i <= m;i++){
		cout << s[i] << ' ';
	}
	return 0;
}
