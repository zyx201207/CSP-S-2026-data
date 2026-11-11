#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n,m;
	scanf("%d %d", &n, &m);
	int A[n];
	for (int i = 0;i<n;i++){
		scanf("%d", &A[i]);
	}
	
	sort(A, A+n);
	
//	double base = 0;
//	for (int i = 0;i<n;i++){
//		base += A[i]; 
//	}
//	base /= n;
	int l = n/2;
//	for (int i = 0;i<10000;i++){
//		int mid = (l+r)/2;
//		if (A[mid] > base){
//			r = mid;
//		}else{
//			l = mid;
//		}
//	}
	int ans = 0;
	for (int i = 0;i<n;i++){
		if (A[i] == A[l]) ans++;
	}
	int ans1 = ans,o=0;
	for (int i = 0;i<n/2 && o<m;i++){
		o += A[l] - A[i]; ans1++;
	}
	int ans2 = ans;o=0;
	for (int i = n/2;i<n && o<m;i++){
		o += A[l] - A[i]; ans2++;
	}
	
	printf("%d", max(ans1, ans2)-1);
	 
	return 0;
} 

// 5 5 1 2 4 8 9
// 5 8 -3 -1 2 2 7
