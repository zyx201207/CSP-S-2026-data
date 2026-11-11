#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	
	sort(arr,arr + n,greater<int>());
	
	int t[n] = {0};
	for(int i = 0;i < n;i++){
		t[i] = arr[i];
		for(int j = 0;j < m;j++){
			t[i] &= arr[i + j];
		}
	}
	
	int mx = 0;
	for(int i = 0;i < n;i++){
		mx = max(mx,t[i]);
	}
	
	cout << mx;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
