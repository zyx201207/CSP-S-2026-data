#include <bits/stdc++.h>
using namespace std;

long long arr[500000];

int fun(int mid,int m){
	for(int i = 0;i < mid;i++){
		arr[i] = arr[mid] - arr[i];
	}
	
	int ans = 1;
	for(int i = mid - 1;i >= 0;i--){
		if(m < arr[i]){
			return ans;
		}
		
		m -= arr[i];
		ans++;
	}
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;
	cin >> n >> m;
	
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	
	sort(arr,arr + n);
	
	int mx = 0;
	for(int i = 0;i < n;i++){
		mx = max(mx,fun(i,m));
	}
	
	cout << mx;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
