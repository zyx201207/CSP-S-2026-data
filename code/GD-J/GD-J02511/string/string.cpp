#include<bits/stdc++.h>
using namespace std;
struct c{
	int x;
	char c;	
}a[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].c;
	}
	if (n == 1){
		printf("0");
		return 0;
	}
	int pos = 1, t = n;
	long long sum = 0;
		while(pos < t){
			if (a[pos].c != a[t].c){
				if (a[pos].x < a[t].x){
					sum += a[pos].x;
					a[t].x -= a[pos].x;
					pos++;
				}else{
					if (a[pos].x != a[t].x){
						sum += a[t].x;
						a[pos].x -= a[t].x;
						t--;
					}else{
						sum += a[t].x;
						pos++;
						t--;
					}		
				}
			}
			else{
				if (a[pos].x < a[t].x){
					a[t].x -= a[pos].x;
					pos++;
				}else{
					if (a[pos].x != a[t].x){
						a[pos].x -= a[t].x;
						t--;
					}else{
						pos++;
						t--;
					}			
				}
			}
		}
	
	printf("%lld", sum);
	return 0;
}

