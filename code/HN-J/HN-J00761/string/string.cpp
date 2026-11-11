#include<bits/stdc++.h>
using namespace std;
long long n, a[200050], cnt;
char c[200050];
int main(){
	//Trick||Treat!
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}for(int i = 1,j = n;i <= j;){
		if(c[i] == c[j]){
			if(a[i] == a[j]){
				i++;
				j--;
			}else if(a[i] > a[j]){
				a[i] -= a[j];
				j--;
			}else if(a[i] < a[j]){
				a[j] -= a[i];
				i++;
			}
		}else{
			if(a[i] == a[j]){
				cnt += a[j];
				i++;
				j--;
			}else if(a[i] > a[j]){
				a[i] -= a[j];
				cnt += a[j];
				j--;
			}else if(a[i] < a[j]){
				a[j] -= a[i];
				cnt += a[i];
				i++;
			}
		}
	}
	cout << cnt;
	return 0;
} 
