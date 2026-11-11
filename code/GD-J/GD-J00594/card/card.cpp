#include<bits/stdc++.h>
using namespace std;
int n, m;
int arr[500010], brr[500010], crr[300010], ans[300010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}
	if(n <= 5000 && m <= 3000){
		for(int k=1; k<=n; k++){
			memset(crr, 0, sizeof(crr));
			int t = 0;
			for(int i=k; i<=n; i++){
				if(crr[arr[i]] == 0){
					brr[++t] = arr[i];
					crr[arr[i]]++;
				}
				else{
					while(brr[t] != arr[i]){
						crr[brr[t]]--;
						t--;
					}
				}
			}
			for(int i=1; i<=t; i++){
				ans[brr[i]]++;
			}
		}
		for(int i=1; i<=m; i++){
			int a = ans[i];
			printf("%d ", a);
		}		
	}
	else if(m <= 2){
		if(m == 1){
			printf("%d", n);
		}
		else{
			if(arr[n] == 1){
				ans[1] = n;
				for(int i=1; i<n; i++){
					if(arr[i] == 2) ans[2]++;
				}
			}
			else if(arr[n] == 2){
				ans[2] = n;
				for(int i=1; i<n; i++){
					if(arr[i] == 1) ans[1]++;
				}
			}
			int a = ans[1], b = ans[2];
			printf("%d %d", a, b);
		}
	}
	else{
		for(int i=1; i<=n; i++){
			ans[arr[i]]++;
		}
		for(int i=1; i<=m; i++){
			ans[i] += ans[i-1];
		}
		for(int i=1; i<=m; i++){
			int a = ans[i];
			printf("%d ", a);
		}
	}
	return 0;
}
