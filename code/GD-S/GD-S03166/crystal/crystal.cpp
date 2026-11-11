#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; long long m;
	cin >> n; cin >> m;
	long long a[n+1];
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	sort(a,a + n + 1);
	int sum = 0;
	/*for(int i = 1;i < n;i ++){
		int left = 0,right = i;
		for(left;left < right;left ++){
			long long cnt = 0;
			for(int j = left;j < right;j ++){
				cnt += (a[right] - a[j]);
			}
			if(cnt > m){
				cnt = 0; left ++;
			}else{
				sum = max(sum,(right - left + 1));
			}
		}
	}*/
	for(int i = n - 1;i > 0;i --){
		int right = i,left = right - 1;
		for(left;left >= 0;left --){
			long long cnt = 0;
			for(int j = right - 1;j >= left;j --){
				cnt += (a[right] - a[j]);
			}
			if(cnt > m){
				cnt = 0; right --;
				break;
			}else{
				sum = max(sum,(right - left + 1));
			}
		}
	}
	
	cout << sum;
	
	return 0;
}
