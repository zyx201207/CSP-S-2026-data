#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
struct node{
	ll x;
	char ch;
}arr[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll cnt = 0; 
	for(int i = 1; i <= n; i ++){
		cin >> arr[i].x >> arr[i].ch;
		cnt = cnt + arr[i].x;
	}
	ll tmp = cnt / 2;
	int i = 1, j = n;
	ll sum = 0;
	ll ans = 0;
	while(sum < tmp){
		if(arr[i].ch != arr[j].ch){
			if(arr[i].x > arr[j].x){
				arr[i].x -= arr[j].x;
				sum += arr[j].x;
				ans += arr[j].x;
				j -= 1;
			}
			else if(arr[i].x < arr[j].x){
				arr[j].x -= arr[i].x;
				sum += arr[i].x;
				ans += arr[i].x;
				i += 1;
			}
			else{
				ans += arr[i].x;
				sum += arr[i].x;
				i += 1;
				j -= 1; 
			}
		}
		else{
			if(arr[i].x > arr[j].x){
				arr[i].x -= arr[j].x;
				sum += arr[j].x;
				j -= 1;
			}
			else if(arr[i].x < arr[j].x){
				arr[j].x -= arr[i].x;
				sum += arr[i].x;
				i += 1;
			}
			else{
				sum += arr[i].x;
				i += 1;
				j -= 1; 
			}
		}
	}
	cout << ans;
	return 0;
}
