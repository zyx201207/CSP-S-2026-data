#include<bits/stdc++.h>
using namespace std;
int n , a[200010];
long long sum = 0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	int l = 1 , r = n;
	long long ls = a[l] , rs = a[r];
	while(l < r){
		if(c[l] == c[r]){
			if(ls >= rs){
				ls -= rs;
				rs = 0;
				r--;
				rs = a[r];
			}else{
				rs -= ls;
				ls = 0;
				l++;
				ls = a[l];
			}
		}else{
			if(ls >= rs){
				ls -= rs;
				sum += rs;
				rs = 0;
				r--;
				rs = a[r];
			}else{
				rs -= ls;
				sum += ls;
				ls = 0;
				l++;
				ls = a[l];
			}
		}
	}
	cout << sum;
	return 0;
}
