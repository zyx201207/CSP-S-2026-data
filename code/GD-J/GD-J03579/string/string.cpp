#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
long long wrg;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cin >> b[i];
	}
	int p1 = 1, p2 = n;
	while(p1 < p2){
		if(b[p1] == b[p2]){
			p1++;
			p2--;
			continue;
		}
		else {
			if(a[p1] == a[p2]){
				wrg += a[p2];
				p1++;
				p2--;
				continue;
			}
			else if(a[p1] > a[p2]){
				wrg += a[p1] - a[p2];
				a[p1] -= a[p2];
				p2--;
				continue;
			}
			else {
				wrg += a[p2] - a[p1];
				a[p2] -= a[p1];
				p1++;
				continue;
			}
		}
	}
	printf("%lld", wrg);
	return 0;
} 
