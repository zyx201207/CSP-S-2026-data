#include <bits/stdc++.h>
using namespace  std;
const int N = 2e5 + 10;
int n;
unsigned long long cnt;
struct st{
	unsigned long long num;
	char ch;
}arr[N];
void check(){
	int l = 1,r = n;
	while (l < r){
		if (arr[l].ch != arr[r].ch){
			cnt += min(arr[l].num,arr[r].num);
		}
		if (arr[l].num < arr[r].num){
			arr[r].num -= arr[l].num;
			l++;
		}else if(arr[l].num > arr[r].num){
			arr[l].num -= arr[r].num;
			r--;
		}else if (arr[l].num == arr[r].num){
			l++;
			r--;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> arr[i].num >> arr[i].ch;
	}
	check();
	cout << cnt;
	return 0;
}
