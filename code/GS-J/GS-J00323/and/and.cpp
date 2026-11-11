#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long  n , m ;cin >> n;
	vector<long long>arr(n);
	cin >> m ;
	for(long long i = 0; i < n ;i++){
		cin >> arr[i];
	} 
 	sort(arr.begin(),arr.end());
 	reverse(arr.begin(),arr.end());
 	int ans = arr[0];
	for(int i= 1 ; i < m ;i ++){
		ans &= arr[i];
	}	
	cout << ans;
}
