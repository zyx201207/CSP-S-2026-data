#include<bits/stdc++.h>
using namespace std;
struct Node{
	char c;
	long long t;
}a[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, sum = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i].t >> a[i].c;
	}
	for(int i = 0, j = n - 1;i <  j;i++, j--){
		if(a[i].c != a[j].c){
			if(a[i].t >= a[j].t){
				sum += a[j].t;
				a[i].t -= a[j].t;
				a[j].t = 0;
				i--;
			}else{
				sum += a[i].t;
				a[j].t -= a[i].t;
				a[i].t = 0;
				j++;
			}
		}else{
			if(a[i].t >= a[j].t){
				a[i].t -= a[j].t;
				a[j].t = 0;
				i--;
			}else{
				a[j].t -= a[i].t;
				a[i].t = 0;
				j++;
			}
		}
	}
	cout << sum;
	return 0;
}
