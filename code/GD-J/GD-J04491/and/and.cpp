#include <cstdio>

int smallest(int* arr, int len){
	int smallest = *arr;
	for(int i = 1; i < len; i++){
		if(*(arr + i) < smallest){
			smallest = *(arr + i);
		}
	}
	return smallest;
}

int find(int* arr, int len, int target){
	for(int i = 0; i < len; i++){
		if(*(arr + i) == target){
			return i;
		}
	}
	return 0;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	scanf("%d %d\n", &n, &m);
	int arr[n], target[m] = {0};
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i-1]);
	}
	
	int small = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] > small){
			target[find(target, m, small)] = arr[i];
			small = smallest(target, m);
		}
	}
	
	int ans = target[0];
	for(int i = 1; i < m; i++){
		if(target[i] != 0){
			ans &= target[i];
		}
	}
	printf("%d", ans);
	
	return 0;
} 
